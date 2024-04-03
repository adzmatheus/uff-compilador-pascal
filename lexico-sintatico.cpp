#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <cctype>
#include <vector>

using namespace std;

#define tk_program 0
#define tk_begin 1
#define tk_end 2
#define tk_const 3
#define tk_type 4
#define tk_var 5
#define tk_integer 6
#define tk_real 7
#define tk_array 8
#define tk_of 9
#define tk_record 10
#define tk_function 11
#define tk_procedure 12
#define tk_while 13
#define tk_if 14
#define tk_then 15
#define tk_write 16
#define tk_read 17
#define tk_else 18
#define tk_trem 19
#define tk_pontoevirgula 20
#define tk_compara 21
#define tk_aspas 22
#define tk_ponto 23
#define tk_doispontos 24
#define tk_virgula 25
#define tk_abrecolchete 26
#define tk_fechacolchete 27
#define tk_abreparenteses 28
#define tk_fechaparenteses 29
#define tk_atribui 30
#define tk_maior 31
#define tk_menor 32
#define tk_diferente 33
#define tk_soma 34
#define tk_subtracao 35
#define tk_multiplicacao 36
#define tk_divisao 37
#define tk_numero 38
#define tk_numeroreal 39
#define tk_EOF 40
#define tk_epsilon 41
#define tk_erro 42

void erro_sint();
void pegatoken();
void programa();
void identificador();
void corpo();
void declaracoes();
void s_begin();
void s_end();
void variavel();
void lista_id();
void lista_id2();
void def_const();
void constantes();
void constantes2();
void constante();
void def_tipos();
void tipos();
void tipos2();
void tipo();
void tipo_dado();
void def_var();
void variaveis();
void variaveis2();
void def_rotina();
void rotina();
void funcao();
void nomerotina();
void blocorotina();
void procedimento();
void bloco();
void comandos();
void comando();
void nome();
void nome2();
void nome_numero();
void op_matematico();
void op_logico();
void exp_matematica();
void exp_matematica2();
void exp_logica();
void exp_logica2();
void s_else();
void parametro();
void lista_param();
void lista_param2();
void numero();
void const_valor();
void exp_matematica();

///TREM (Token Relacionado a Entrada Manual)

int linha_leitura = 1;

/// ANALISADOR LÉXICO /////////////////////////////////

///Verifica se é um símbolo válido
int issimbolo(char c) {
	if (c == ';' || c == '=' || c == '"' || c == '.' || c == ':' ||
		c == ',' || c == '[' || c == ']' || c == '(' || c == ')' ||
		c == '>' || c == '<' || c == '!' || c == '+' || c == '-' ||
		c == '*' || c == '/' )
		return 1;
    else
        return 0;
}

///Verifica qual é o símbolo
int simbolo(char *lex){

    if(lex[0] == ';')
        return tk_pontoevirgula;

    else if(lex[0] == '=')
        return tk_compara;

    else if(lex[0] == '"')
        return tk_aspas;

    else if(lex[0] == '.')
        return tk_ponto;

    else if(strcmp(lex,":=") == 0)
        return tk_atribui;

    else if(lex[0] == ':')
        return tk_doispontos;

    else if(lex[0] == ',')
        return tk_virgula;

    else if(lex[0] == '[')
        return tk_abrecolchete;

    else if(lex[0] == ']')
        return tk_fechacolchete;

    else if(lex[0] == '(')
        return tk_abreparenteses;

    else if(lex[0] == ')')
        return tk_fechaparenteses;

    else if(lex[0] == '>')
        return tk_maior;

    else if(lex[0] == '<')
        return tk_menor;

    else if(lex[0] == '!')
        return tk_diferente;

    else if(lex[0] == '+')
        return tk_soma;

    else if(lex[0] == '-')
        return tk_subtracao;

    else if(lex[0] == '*')
        return tk_multiplicacao;

    else if(lex[0] == '/')
        return tk_divisao;

    }

///Verifica se é uma palavra reservada ou um TREM
int palavra(char *lex)
{
    int i;
    string palavrasreservadas[]={"program","begin","end","const","type","var","integer","real",
                                 "array","of","record","function","procedure","while","if","then",
                                 "write","read","else"};
    for(i=0; i<19 ;i++)
        if(strcmp(lex, palavrasreservadas[i].c_str())==0)
            return i;
    return tk_trem;
}

///Recebe um número e retorna o padrão do tk
char *classifica_tk(int tipo_tk){
    char *tipo;

    switch (tipo_tk)
    {
        case 0:
         tipo = "tk_program";
       break;

       case 1:
         tipo = "tk_begin";
       break;

       case 2:
         tipo = "tk_end";
       break;

       case 3:
         tipo = "tk_const";
       break;

       case 4:
         tipo = "tk_type";
       break;

       case 5:
         tipo = "tk_var";
       break;

       case 6:
         tipo = "tk_integer";
       break;

       case 7:
         tipo = "tk_real";
       break;

       case 8:
         tipo = "tk_array";
       break;

       case 9:
         tipo = "tk_of";
       break;

       case 10:
         tipo = "tk_record";
       break;

       case 11:
         tipo = "tk_function";
       break;

       case 12:
         tipo = "tk_procedure";
       break;

       case 13:
         tipo = "tk_while";
       break;

       case 14:
         tipo = "tk_if";
       break;

       case 15:
         tipo = "tk_then";
       break;

       case 16:
         tipo = "tk_write";
       break;

       case 17:
         tipo = "tk_read";
       break;

       case 18:
         tipo = "tk_else";
       break;

       case 19:
         tipo = "tk_trem";
       break;

       case 20:
         tipo = "tk_pontoevirgula";
       break;

       case 21:
         tipo = "tk_compara";
       break;

       case 22:
         tipo = "tk_aspas";
       break;

       case 23:
         tipo = "tk_ponto";
       break;

       case 24:
         tipo = "tk_doispontos";
       break;

       case 25:
         tipo = "tk_virgula";
       break;

       case 26:
         tipo = "tk_abrecolchete";
       break;

       case 27:
         tipo = "tk_fechacolchete";
       break;

       case 28:
         tipo = "tk_abreparenteses";
       break;

       case 29:
         tipo = "tk_fechaparenteses";
       break;

       case 30:
         tipo = "tk_atribui";
       break;

       case 31:
         tipo = "tk_maior";
       break;

       case 32:
         tipo = "tk_menor";
       break;

       case 33:
         tipo = "tk_diferente";
       break;

       case 34:
         tipo = "tk_soma";
       break;

       case 35:
         tipo = "tk_subtracao";
       break;

       case 36:
         tipo = "tk_multiplicacao";
       break;

       case 37:
         tipo = "tk_divisao";
       break;

       case 38:
         tipo = "tk_numero";
       break;

       case 39:
         tipo = "tk_numeroreal";
       break;

       case 40:
         tipo = "tk_EOF";
       break;

       case 41:
         tipo = "tk_epsilon";
       break;

       case 42:
         tipo = "tk_erro";
       break;

       default:
         tipo = "erro";
    }
    return tipo;
}

struct token {
    char lexema[20]; //O que foi encontrado no codigo
    char *tk; //de acordo com os padroes, o que é
    int linha; //em que linha do codigo foi encontrado
};
token v_token[500];
int indice = 0;

///Pega token por token e imprime em um arquivo o token, a linha, o tipo de terminal que o token é
int pegalexema( FILE * codigo, FILE * objeto ){
    token aux;
    char c;
    char cad[2];
    char cadeia[100];

    strcpy( cadeia , "" ); //limpa cadeia de caracteres

    c = fgetc(codigo);

    if( c == ' ' )
    {
        return 0;
    }
    if( c == '\n' )
    {
        linha_leitura++;
        return 0;
    }

    if(c == EOF)
    {
        //cout << "FIM DO ARQUIVO" << endl;
        fclose(objeto);
        return 1;
    }

    if(isdigit(c)) //Verifica se é um número real ou inteiro
    {
        while(isdigit(c))
        {
            cad[0] = c;
            cad[1] = '\0';
            strcat(cadeia, cad);
            c = fgetc(codigo);
        }
        if(c != '.')
        {
            strcpy(aux.lexema,cadeia);
            aux.linha = linha_leitura;
            aux.tk = classifica_tk(tk_numero);
            v_token[indice] = aux;
            indice++;
            //cout << cadeia << " linha "<< linha_leitura << " class " << classifica_tk(tk_numero) << endl;
            fprintf(objeto, "%s", cadeia);
            fprintf(objeto, "%s", "    ");
            fprintf(objeto, "%d", linha_leitura);
            fprintf(objeto, "%s", "    ");
            fprintf(objeto, "%s", "tk_numero");
            fprintf(objeto, "%s", "\n");
            fseek(codigo,-1,SEEK_CUR);
            return 0;
        }else{
            cad[0] = c;
            cad[1] = '\0';
            strcat(cadeia, cad);
            c = fgetc(codigo);
            if(isdigit(c))
            {
                while(isdigit(c))
                {
                    cad[0] = c;
                    cad[1] = '\0';
                    strcat(cadeia, cad);
                    c = fgetc(codigo);
                }
                strcpy(aux.lexema,cadeia);
                aux.linha = linha_leitura;
                aux.tk = classifica_tk(tk_numeroreal);
                v_token[indice] = aux;
                indice++;
                //cout << cadeia << " linha "<< linha_leitura << " class " << classifica_tk(tk_numeroreal) << endl;
                fprintf(objeto, "%s", cadeia);
                fprintf(objeto, "%s", "    ");
                fprintf(objeto, "%d", linha_leitura);
                fprintf(objeto, "%s", "    ");
                fprintf(objeto, "%s", "tk_numeroreal");
                fprintf(objeto, "%s", "\n");
                fseek(codigo,-1,SEEK_CUR);
                return 0;
            }
        }
    }

    if(isalpha(c)) //Verifica se é uma cadeia de caracteres
    {
        while( isalpha(c) || isdigit(c) )
        {
            cad[0] = c;
            cad[1] = '\0';
            strcat(cadeia, cad);
            c = fgetc(codigo);
        }
        strcpy(aux.lexema,cadeia);
        aux.linha = linha_leitura;
        aux.tk = classifica_tk(palavra(cadeia));
        v_token[indice] = aux;
        indice++;
        //cout << cadeia << " linha "<< linha_leitura << " class " << classifica_tk(palavra(cadeia)) << endl;
        fprintf(objeto, "%s", cadeia);
        fprintf(objeto, "%s", "    ");
        fprintf(objeto, "%d", linha_leitura);
        fprintf(objeto, "%s", "    ");
        fprintf(objeto, "%s", classifica_tk(palavra(cadeia)));
        fprintf(objeto, "%s", "\n");
        if(c == EOF)
        {
            //cout << "FIM DO ARQUIVO" << endl;
            fclose(objeto);
            return 1;
        }
        fseek(codigo,-1,SEEK_CUR);
        return 0;
    }

    if(issimbolo(c) && (c != EOF))
    {
        cad[0] = c;
        cad[1] = '\0';
        strcat(cadeia, cad);

        if(c == ':'){
            c = fgetc(codigo);
            if(c == '='){
                cad[0] = c;
                cad[1] = '\0';
                strcat(cadeia, cad);
            }
        }
        strcpy(aux.lexema,cadeia);
        aux.linha = linha_leitura;
        aux.tk = classifica_tk(simbolo(cadeia));
        v_token[indice] = aux;
        indice++;
        //cout << cadeia << " linha "<< linha_leitura << " class " << classifica_tk(simbolo(cadeia)) << endl;
        fprintf(objeto, "%s", cadeia);
        fprintf(objeto, "%s", "    ");
        fprintf(objeto, "%d", linha_leitura);
        fprintf(objeto, "%s", "    ");
        fprintf(objeto, "%s", classifica_tk(simbolo(cadeia)));
        fprintf(objeto, "%s", "\n");
        return 0;
    }

    if(!issimbolo(c)) //Passou por tudo e não é nada, é erro
    {
        cad[0] = c;
        cad[1] = '\0';
        strcat(cadeia, cad);
        strcpy(aux.lexema,cadeia);
        aux.linha = linha_leitura;
        aux.tk = classifica_tk(tk_erro);
        v_token[indice] = aux;
        indice++;
        //cout << cadeia << " linha "<< linha_leitura << " class " << classifica_tk(tk_erro) << endl;
        fprintf(objeto, "%s", cadeia);
        fprintf(objeto, "%s", "    ");
        fprintf(objeto, "%d", linha_leitura);
        fprintf(objeto, "%s", "    ");
        fprintf(objeto, "%s", classifica_tk(tk_erro));
        fprintf(objeto, "%s", "\n");
        return 0;
    }
}

int printoken (token tk){
    cout << tk.lexema << " _ " << tk.tk << " _ " << tk.linha << endl;
    return 0;
}


/// ANALISADOR SINTÁTICO /////////////////////////////////////
token atual;
int erro = 0;

void erro_sint(){
    cout << "* Erro sintatico *  - Token: " << atual.lexema << " - Linha: "<< atual.linha << endl;
}

void pegatoken(){
    indice++;
    atual = v_token[indice];
    //printf("Pego : %s\n",atual.lexema);
}

int verifica(int tk){
    if (atual.tk == classifica_tk(tk)){
        //cout << "Correto:" << atual.tk << " - " << classifica_tk(tk) << " - " << atual.lexema << endl;
        return 1;
    }
    else{
        //cout << "Errado:" << atual.tk << " - " << classifica_tk(tk) << " - " << atual.lexema << endl;
        return 0;
    }
}

void identificador(token tk){

}

void programa(){
    if (verifica(tk_program)){
        pegatoken();
        if (verifica(tk_trem)){
            pegatoken();
            if (verifica(tk_pontoevirgula)){
                corpo();
            }
            else{
                erro_sint();
            }
        }
        else{
            erro_sint();
        }
    }
    else{
        erro_sint();
    }
}

void corpo(){
    declaracoes();
    pegatoken();
    if (verifica(tk_begin)){
        comandos();
        pegatoken();
        if (verifica(tk_end)){
            cout << "Analise sintatica concluida" << endl;
        }
        else{
            erro_sint();
        }
    }
    else{
        erro_sint();
    }

}

void declaracoes(){
    def_const();
    def_tipos();
    def_var();
    def_rotina();
}

void def_const(){
    pegatoken();
    if(verifica(tk_const)){
        constantes();
    }
    else{
        indice--;
    }
}

void constantes(){
    constante();
    constantes2();
}

void constantes2(){
    pegatoken();
    if (verifica(tk_trem)){
        indice--;
        constantes();
    }
    indice--;
}

void constante(){
    pegatoken();
    if (verifica(tk_trem)){
        pegatoken();
        if (verifica(tk_compara)){
            const_valor();
            pegatoken();
            if(!verifica(tk_pontoevirgula)){
                erro_sint();
            }
        }
        else{
            erro_sint();
        }
    }
    else{
        erro_sint();
    }
}

void const_valor(){
    pegatoken();
    if(verifica(tk_numero) || verifica(tk_trem)){
        indice--;
        exp_matematica();
    }

    else if(verifica(tk_aspas)){
        pegatoken();
        while(!verifica(tk_aspas)){
            pegatoken();
        }
    }
    else{
        erro_sint();
    }
}

void def_tipos(){
    pegatoken();
    if(verifica(tk_type)){
        tipos();
    }
    else{
        indice--;
    }
}

void tipos(){
    tipo();
    tipos2();
}

void tipos2(){
    pegatoken();
    if(verifica(tk_pontoevirgula)){
        pegatoken();
        if (verifica(tk_trem)){
            indice--;
            tipos();
        }
        else{
            indice--;
        }
    }
}

void tipo(){
    pegatoken();
    if (verifica(tk_trem)){
        pegatoken();
        if (verifica(tk_compara)){
            tipo_dado();
        }
        else{
            erro_sint();
        }
    }
    else{
        erro_sint();
    }
}

void tipo_dado(){
    pegatoken();
    if ( verifica(tk_trem) || verifica(tk_integer) || verifica(tk_real) ){

    }
    else if(verifica(tk_record)){
        variaveis();
        pegatoken();
        if(!verifica(tk_end)){
            erro_sint();
        }
    }
    else if(verifica(tk_array)){
        pegatoken();
        if(verifica(tk_abrecolchete)){
            pegatoken();
            if(verifica(tk_numero)){
                pegatoken();
                if (verifica(tk_fechacolchete)){
                    pegatoken();
                    if (verifica(tk_of)){
                        tipo_dado();
                    }
                }
                else{
                    erro_sint();
                }
            }
            else{
                erro_sint();
            }
        }
        else{
            erro_sint();
        }
    }
    else{
        erro_sint();
    }
}

void variaveis(){
    variavel();
    variaveis2();
}

void variaveis2(){
    pegatoken();
    if(verifica(tk_pontoevirgula)){
        pegatoken();
        if(verifica(tk_trem)){
            indice--;
            variaveis();
        }
        else{
            indice--;
        }
    }
    else{
        indice--;
    }
}

void variavel(){
    lista_id();
    pegatoken();
    if(verifica(tk_doispontos)){
        tipo_dado();
    }
    else{
        erro_sint();
    }
}

void lista_id(){
    pegatoken();
    if(verifica(tk_trem)){
        lista_id2();
    }
    else{
        erro_sint();
    }
}

void lista_id2(){
    pegatoken();
    if (verifica(tk_virgula)){
        lista_id();
    }
    else{
        indice--;
    }
}

void def_var(){
    pegatoken();
    if (verifica(tk_var)){
        variaveis();
    }
    else{
        indice--;
    }
}

void def_rotina(){
    pegatoken();
    if(verifica(tk_function)){
        indice--;
        funcao();
        def_rotina();
    }
    else if(verifica(tk_procedure)){
        indice--;
        procedimento();
        def_rotina();
    }
    else{
        indice--;
    }
}

void funcao(){
    pegatoken();
    if (verifica(tk_function)){
        nomerotina();
        pegatoken();
        if(verifica(tk_doispontos)){
            tipo_dado();
            blocorotina();
        }
        else{
            erro_sint();
        }
    }
    else{
        erro_sint();
    }
}

void nomerotina(){
    pegatoken();
    if(verifica(tk_trem)){
        pegatoken();
        if(verifica(tk_abreparenteses)){
            pegatoken();
            if(verifica(tk_trem)){
                indice--;
                variaveis();
            }
            else{
                indice--;
            }
            pegatoken();
            if(!verifica(tk_fechaparenteses)){
                erro_sint();
            }
        }
        else{
            erro_sint();
        }
    }
    else{
        erro_sint();
    }
}

void blocorotina(){
    pegatoken();
    if(verifica(tk_var)){
        indice--;
        def_var();
    }
    else{
       indice--;
    }
    bloco();
}

void bloco(){
    pegatoken();
    if(verifica(tk_begin)){
        comandos();
        pegatoken();
        if(!verifica(tk_end)){
            erro_sint();
        }
    }
    else{
        indice--;
        comando();
    }
}

void nome(){
    pegatoken();
    if(verifica(tk_trem)){
        nome2();
    }
}

void nome2(){
    pegatoken();
    if (verifica(tk_ponto)){
        nome();
    }
    else if(verifica(tk_abrecolchete)){
        nome_numero();
        pegatoken();
        if(!verifica(tk_fechacolchete)){
            erro_sint();
        }
    }
    else{
        indice--;
    }
}

void numero(){
    pegatoken();
    if( !(verifica(tk_numero) || verifica(tk_numeroreal)) ){
        erro_sint();
    }
}

void nome_numero(){
    pegatoken();
    if (verifica(tk_trem)){
        pegatoken();
        if (verifica(tk_abreparenteses)){
            parametro();
            pegatoken();
            if(!verifica(tk_fechaparenteses)){
                erro_sint();
            }
        }
        else{
            indice--;
            indice--;
            nome();
        }
    }
    else if(verifica(tk_numero)){
        indice--;
        numero();
    }
}

void parametro(){
    pegatoken();
    if(verifica(tk_trem)){
        indice--;
        lista_param();
    }
    else{
        indice--;
    }
}

void lista_param(){
    nome_numero();
    lista_param2();
}

void lista_param2(){
    pegatoken();
    if(verifica(tk_virgula)){
        lista_param();
    }
    else{
        indice--;
    }
}

void s_else(){
    pegatoken();
    if(verifica(tk_else)){
        bloco();
    }
    else{
        indice--;
    }
}

void procedimento(){
    pegatoken();
    if(verifica(tk_procedure)){
        nomerotina();
        blocorotina();
    }
    else{
        erro_sint();
    }

}

void comandos(){
    pegatoken();
    if(verifica(tk_trem) || verifica(tk_while) || verifica(tk_if) || verifica(tk_write) || verifica(tk_read)){
        indice--;
        comando();
        pegatoken();
        if(verifica(tk_pontoevirgula)){
            comandos();
        }
        else{
            erro_sint();
        }
    }
    else{
        indice--;
    }
}

void comando(){
    pegatoken();
    if (verifica(tk_trem)){
        indice--;
        nome();
        pegatoken();
        if(verifica(tk_atribui)){
            exp_matematica();
        }
        else{
            erro_sint();
        }
    }
    else if(verifica(tk_while)){
        exp_logica();
        bloco();
    }
    else if(verifica(tk_if)){
        exp_logica();
        pegatoken();
        if(verifica(tk_then)){
            bloco();
            s_else();
        }
    }
    else if(verifica(tk_write)){
        const_valor();
    }
    else if(verifica(tk_read)){
        nome();
    }
    else{
        erro_sint();
    }
}

void exp_matematica(){
    pegatoken();
    if(verifica(tk_abreparenteses)){
        nome_numero();
        op_matematico();
        exp_matematica();
        pegatoken();
        if(!verifica(tk_fechaparenteses)){
            erro_sint();
        }
    }
    else{
        indice--;
        nome_numero();
        exp_matematica2();
    }
}

void exp_matematica2(){
    pegatoken();
    if(verifica(tk_soma) || verifica(tk_subtracao) || verifica(tk_multiplicacao) || verifica(tk_divisao)){
        indice--;
        op_matematico();
        exp_matematica();
    }
    else{
        indice--;
    }
}

void exp_logica(){
    exp_matematica();
    exp_logica2();
}

void exp_logica2(){
    pegatoken();

    if(verifica(tk_maior) || verifica(tk_menor) || verifica(tk_compara) || verifica(tk_diferente)){
        indice--;
        op_logico();
        exp_logica();
    }
    else{
        indice--;
    }
}

void op_logico(){
    pegatoken();
    if(verifica(tk_maior) || verifica(tk_menor) || verifica(tk_compara) || verifica(tk_diferente))
    {
        ///Se for operador logico ok
    }else{
        erro_sint();
    }
}

void op_matematico(){
    pegatoken();
    if(verifica(tk_soma) || verifica(tk_subtracao) || verifica(tk_multiplicacao) || verifica(tk_divisao))
    {
        ///Se for operador matematico ok
    }else{
        erro_sint();
    }
}

void sintatico(){
    indice = 0;
    atual = v_token[indice];
    programa();
}

int main()
{
    FILE *cod = fopen("codigo.txt","rt");
    FILE *objeto = fopen("pre_tokenized_cod.txt", "wt");

    int estado = 0;

    while (estado == 0){
        estado = pegalexema(cod, objeto);
    }
    cout << "Analise lexica concluida" << endl;

    sintatico();

    return 0;
}
