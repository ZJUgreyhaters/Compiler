/* v-1.1
 * test.c 有很多bug，还在调试条件语句body的bug
int main(double x, int tmp2, double y) {
    int a, b, c, d;
    a = c + d * c;


    for(i = 0;a < 1;a = a + 1){
        a = c + d;
        b = a + 1;
    }

    if(a > 0) {
        c = a;
    }

    while(a > c){
        d = c + d;
    }

    return a;
}

int test() {
    int s;
    return 0;
}
*/


#include "codeGen.h"

int paraNumber = 1;

int conditionNumber = 0;

char instruction[1024][32];
int ip = 0;

char reg[64][5] = {"$R0", "$R1", "$R2", "$R3", "$R4", "$R5", "$R6", "$R7", "$R8", "$R9", "$R10", "$R11", "$R12", "$R13", "$R14", "$R15", "$R16", "$R17", "$R18", "$R19", "$R20", "$R21", "$R22", "$R23", "$R24", "$R25", "$R26", "$R27", "$R28", "$R29", "$R30", "$R31", "$R32", "$R33", "$R34", "$R35", "$R36", "$R37", "$R38", "$R39", "$R40", "$R41", "$R42", "$R43", "$R44", "$R45", "$R46", "$R47", "$R48", "$R49", "$R50", "$R51", "$R52", "$R53", "$R54", "$R55", "$R56", "$R57", "$R58", "$R59", "$R60", "$R61", "$R62", "$R63"};
int regindex = 1;

void codeGen(Tree t) //传入全局变量root
{
    //printf("\n----    IR-Code    ----\n");
    //printf("//%s\n", t->kind);
    if(t == NULL) {
        return;
    }

    if(strcmp(t->kind, "function_definition") == 0) {
        funCode(t);//函数为一个基本代码块
    }
    else {
        codeGen(t->firstChild);
        codeGen(t->nextSibling);
    }
}

void funCode(Tree t)
{
    Tree re_type = t->firstChild;       //函数返回类型
    Tree identifier = re_type->nextSibling;//函数名
    Tree tmp = identifier->nextSibling;
    Tree paraList = NULL;               //函数形参列表，可能没有参数
    Tree compStat = NULL;               //函数体

    if(strcmp(tmp->kind, "parameter_list") == 0) {
        paraList = tmp;
        compStat = paraList->nextSibling;
    }
    else {
        compStat = tmp;
    }
    paraListCode(paraList);//参数生成
    printf("Func %s:\n", identifier->content); //输出函数名标签 "fun_name : "
    compStatCode(compStat);//函数体代码生成
}

void paraListCode(Tree t)
{
    if(t == NULL) {
        return;
    }
    
    if(strcmp(t->kind, "parameter_declaration") == 0) {
        printf("para%d %s\n", paraNumber++, t->firstChild->nextSibling->content);//输出 "para1 para_name"
        return;
    }
    else {
        paraListCode(t->firstChild);
        paraListCode(t->firstChild->nextSibling);
    }
}

void compStatCode(Tree t)
{
    if(t == NULL) {
        return;
    }
    Tree statList = t->firstChild;
    statListCode(statList);
}

void statListCode(Tree t)
{
    if(t == NULL) {
        return;
    }
    if(strcmp(t->kind, "statement_list") == 0) {
        statListCode(t->firstChild);
        statListCode(t->nextSibling);
    }
    else if(strcmp(t->kind, "statement") == 0) {
        statementCode(t);
    }
}

void statementCode(Tree t)
{
    if(t == NULL) {
        return;
    }
    Tree concrete_stat = t->firstChild;
    if(strcmp(concrete_stat->kind, "compound_statement") == 0){
        compStatCode(concrete_stat);
    }
    else if(strcmp(concrete_stat->kind, "expression") == 0) {
        expCode(concrete_stat);
    }
    else if(strcmp(concrete_stat->kind, "selection_statement") == 0) {
        conditionCode(concrete_stat);
    }
    else if(strcmp(concrete_stat->kind, "iteration_statement") == 0) {
        loopCode(concrete_stat);
    }
    else if (strcmp(concrete_stat->kind, "jump_statement") == 0)
    {
        returnCode(concrete_stat);
    }
    else if(strcmp(concrete_stat->kind, "declaration") == 0) {
        
        //printf("//declaration\n");
    }
}

void expCode(Tree t)
{
    if(t == NULL) {
        return;
    }
    Tree tmp = t->firstChild;

    if(strcmp(tmp->kind, "IDENTIFIER") == 0) {
        standexpCode(tmp);
    }
    else if(strcmp(tmp->kind, "relational_expression") == 0) {
        relationexpCode(tmp);
    }
}

//t 指向IDENTIFER 节点
void standexpCode(Tree t)
{
    //printf("//debug--standexpCode\n");
   
    if(t == NULL) {
        return;
    }

    Tree tmp = t->nextSibling->nextSibling->firstChild->firstChild;//tmp 指向relational_exp 子节点
    //printf("%s-- %s\n", tmp->kind, t->content);

    Tree multiexp = NULL;

    strcat(instruction[ip], t->content);
    strcat(instruction[ip], " = $R0 + ");
    strcat(instruction[ip], reg[regindex]);
    //printf("%s = $R0 + $R%d\n", t->content, regindex);
    ip++;
    regindex++;


    do{
        if(strcmp(tmp->firstChild->kind, "additive_expression") == 0) {
            //printf("%d %d\n", ip, regindex);
            strcat(instruction[ip], reg[regindex - 1]);
            strcat(instruction[ip], " = ");
            strcat(instruction[ip], reg[regindex + 1]);
            strcat(instruction[ip], tmp->firstChild->nextSibling->kind);
            strcat(instruction[ip], reg[regindex]);

            ip++;
            //printf("$R%d = $R%d %s $R%d\n", regindex - 1, regindex + 1, tmp->firstChild->nextSibling->content,regindex);
            multiexp = tmp->firstChild->nextSibling->nextSibling;
            //printf("%s\n", multiexp->firstChild->kind);
            if(strcmp(multiexp->firstChild->kind, "unary_expression") == 0) {
                //printf("//add->multi->unary\n");
                strcat(instruction[ip], reg[regindex]);
                strcat(instruction[ip], " = $R0 + ");
                strcat(instruction[ip], multiexp->firstChild->firstChild->firstChild->firstChild->content);

                ip++;
                //printf("$R%d = $R0 + %s\n", regindex, multiexp->firstChild->firstChild->firstChild->firstChild->content);
            }
            else if(strcmp(multiexp->firstChild->kind, "multiplicative_expression") ==0) {
                //printf("//add->multi->multi\n");
                strcat(instruction[ip], reg[regindex]);
                strcat(instruction[ip], " = ");
                strcat(instruction[ip], multiexp->firstChild->firstChild->firstChild->firstChild->firstChild->content);
                strcat(instruction[ip], " ");
                strcat(instruction[ip], multiexp->firstChild->nextSibling->kind);
                strcat(instruction[ip], " ");
                strcat(instruction[ip], multiexp->firstChild->nextSibling->nextSibling->firstChild->firstChild->firstChild->content);
                //printf("%s\n",  multiexp->firstChild->nextSibling->nextSibling->firstChild->firstChild->firstChild->content);

                ip++;
                //printf("$R%d = %s %s %s\n", regindex, multiexp->firstChild->firstChild->firstChild->firstChild->firstChild->content, multiexp->firstChild->nextSibling->content, multiexp->->firstChild->firstChild->firstChild->firstChild->firstChild->firstChild->content);
            }
            regindex = regindex + 2;
        }
        else if(strcmp(tmp->firstChild->kind, "multiplicative_expression") == 0) {
            //printf("--%d\n", ip);
            multiexp = tmp->firstChild;

            if(strcmp(multiexp->firstChild->kind, "unary_expression") == 0) {

                strcat(instruction[ip], reg[regindex - 1]);

                strcat(instruction[ip], " = $R0 + ");

                strcat(instruction[ip], multiexp->firstChild->firstChild->firstChild->firstChild->content);

                ip++;
                //printf("$R%d = $R0 + %s\n", regindex - 1, multiexp->firstChild->firstChild->firstChild->firstChild->content);
            }
            else if(strcmp(multiexp->firstChild->kind, "multiplicative_expression") ==0) {
                strcat(instruction[ip], reg[regindex - 1]);
                strcat(instruction[ip], " = ");
                strcat(instruction[ip], multiexp->firstChild->firstChild->firstChild->firstChild->firstChild->content);
                strcat(instruction[ip], " ");
                strcat(instruction[ip], multiexp->firstChild->nextSibling->kind);
                strcat(instruction[ip], " ");
                strcat(instruction[ip], multiexp->firstChild->firstChild->firstChild->firstChild->firstChild->firstChild->content);

                ip++;
                //printf("$R%d = %s %s %s\n", regindex - 1, multiexp->firstChild->firstChild->firstChild->firstChild->firstChild->content, multiexp->firstChild->nextSibling->content, multiexp->->firstChild->firstChild->firstChild->firstChild->firstChild->firstChild->content);
            }
        }
        tmp = tmp->firstChild;
    }while(strcmp(tmp->kind, "additive_expression") == 0);

    int i = ip - 1;
    for(;i>=0;i--) {
        puts(instruction[i]);
        memset(instruction[i], 0, 20);
    }
    ip = 0;
}

void conditionCode(Tree t)
{
    Tree exp = t->firstChild->nextSibling;
    Tree stat = exp->nextSibling->firstChild->firstChild;
    Tree else_stat = NULL;

    printf("//---if clause start\n");
    if(stat->nextSibling == NULL) { //没有ELSE语句
        //if false exp goto lable 
        printf("if FALSE ");
        expCode(exp);
        printf("goto lable%d\n", conditionNumber);
        statListCode(stat);
        //lable 
        printf("lable%d:\n", conditionNumber);
        conditionNumber++;
    }
    else {
        else_stat = t->firstChild->nextSibling->nextSibling->nextSibling->nextSibling->firstChild->firstChild;

        //if false exp goto lable 1
        printf("if FALSE ");
        expCode(exp);
        printf("goto lable%d\n", conditionNumber);
        statListCode(stat);
        //goto lable 2
        printf("goto lable%d:\n", ++conditionNumber);
        //lable 1
        printf("lable%d:\n", conditionNumber - 1);
        statListCode(else_stat);
        //lable 2        
        printf("lable%d:\n", conditionNumber);

        conditionNumber++;
    }
    printf("//---if end\n");
}

void relationexpCode(Tree t)
{
    if(strcmp(t->firstChild->kind, "additive_expression") == 0) {
        printf("%s ", t->firstChild->firstChild->firstChild->firstChild->firstChild->firstChild->content);
    }
    else if(strcmp(t->firstChild->kind, "relational_expression") == 0) {

        printf("%s ", t->firstChild->firstChild->firstChild->firstChild->firstChild->firstChild->firstChild->content);
        printf("%s ", t->firstChild->nextSibling->kind);
        printf("%s ", t->firstChild->nextSibling->nextSibling->firstChild->firstChild->firstChild->firstChild->firstChild->content);
    }
}

void loopCode(Tree t)
{
    if(t == NULL) {
        return;
    }
    
    printf("//loop +++++++++ start\n");
    if(strcmp(t->firstChild->kind, "WHILE") == 0) {
        printf("lable%d:\n", conditionNumber++);
        printf("if FALSE ");
        expCode(t->firstChild->nextSibling->nextSibling);
        printf("goto lable%d\n", conditionNumber++);

        statListCode(t->firstChild->nextSibling->nextSibling->nextSibling->nextSibling->firstChild->firstChild);
        //printf("%s\n", t->firstChild->nextSibling->nextSibling->nextSibling->nextSibling->firstChild->kind);
        printf("goto lable%d\n", conditionNumber - 2);
        printf("lable%d\n", conditionNumber - 1);
    }
    else if(strcmp(t->firstChild->kind, "FOR") == 0) {
        //printf("%s\n", t->firstChild->nextSibling->nextSibling->firstChild->kind);
        expCode(t->firstChild->nextSibling->nextSibling->firstChild);
        printf("lable%d:\n", conditionNumber++);

        printf("if FALSE ");
        expCode(t->firstChild->nextSibling->nextSibling->nextSibling->firstChild);
        printf("goto lable%d\n", conditionNumber++);//判断
        statListCode(t->firstChild->nextSibling->nextSibling->nextSibling->nextSibling->nextSibling->nextSibling->firstChild->firstChild);//for 主体

        expCode(t->firstChild->nextSibling->nextSibling->nextSibling->nextSibling);
        printf("goto lable%d\n", conditionNumber - 2);
        printf("lable%d:\n", conditionNumber - 1);
    }
    printf("//loop ++++++++ end\n");
}

void returnCode(Tree t)
{
    //支持单个变量return x; return 3;
    Tree exp = t->firstChild->nextSibling;
    printf("return %s\n", exp->firstChild->firstChild->firstChild->firstChild->firstChild->firstChild->firstChild->content);
}