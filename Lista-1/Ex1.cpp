// Questão 1 - Lista 1 de Estrutura de Dados
// Aluno - Gabriel Belinski Salomão

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

void verificaOcorrencias(string strstr1, string strstr2, FILE *fout){
    size_t pos = strstr2.find(strstr1);
    size_t temp;
    bool nao_ocorre = false;

        while(1){
            bool flag = pos != string::npos;
            if(flag){
                temp = pos+1;
                fprintf(fout, "%d ", temp);
                pos = strstr2.find(strstr1, pos+1);
            }
            else{
                nao_ocorre = true;
                break;
            }
        }

        if(nao_ocorre && temp == 0){
            fprintf(fout, "0");
        }
}

string complementaStr(string strstr1, int n1){
    string strstr3;

    for(int i = 0; i < n1; i++){
        if(strstr1[i] == 'A'){
            strstr3.push_back('T');
        }
        else if(strstr1[i] == 'T'){
            strstr3.push_back('A');
        }
        else if(strstr1[i] == 'C'){
            strstr3.push_back('G');
        }
        else if(strstr1[i] == 'G'){
            strstr3.push_back('C');
        }
    }
    return strstr3;
}

string inverteStr(string strstr1, int n1){
    string strstr4;

    for(int i = n1-1; i >= 0; i--){
        strstr4.push_back(strstr1[i]);
    }
    return strstr4;
}

int main(){
    FILE *fin;
    FILE *fout;

    int n1, n2;

    fin = fopen("genoma.in", "r");
    fout = fopen("genoma.out", "w");

    if(fin && fout){
        int teste = 1;
        while(fscanf(fin, "%d %d", &n1, &n2) && n1 != 0 && n2 != 0){
            fprintf(fout, "Teste %d\n", teste++);

            char *str1 = (char*)malloc(n1*sizeof(char));
            char *str2 = (char*)malloc(n2*sizeof(char));

            fscanf(fin, "%s", str1);
            fscanf(fin, "%s", str2);

            string strstr1;
            string strstr2;

            for(int i = 0; i < n1; i++){
                strstr1.push_back(str1[i]);
            }

            for(int i = 0; i < n2; i++){
                strstr2.push_back(str2[i]);
            }

            free(str1);
            free(str2);

            fprintf(fout, "ocorrencia direta: ");
            verificaOcorrencias(strstr1, strstr2, fout);
            fprintf(fout, "\n");
            fprintf(fout, "ocorrencia complementar invertida: ");
            string strstr3 = inverteStr(complementaStr(strstr1, n1), n1);
            verificaOcorrencias(strstr3, strstr2, fout);
            fprintf(fout, "\n\n");

            strstr1.clear();
            strstr2.clear();
            strstr3.clear();
        }
    }
    else{
        cout << "Erro na abertura/criação dos arquivos. Saindo..." << endl;
        exit(-1);
    }
    fclose(fin);
    fclose(fout);
}
