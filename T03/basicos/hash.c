
int hashFunc(long int cpf){
    int ind = (cpf * 31) % tam;
    return ind;
}

void criarHashItem(hashItem * itemHash, tipoItem item, unsigned int index){
    itemhash->index = index;
    itemHash->prox = NULL;
    itemHash->cpf = item.cpf;
    return ;
}

void popularSistema(FILE * arq, ABP * arv, hashItem hash[]){
/*inserir no arquivpo
    pegar o index do registro
inserir no hash com o indicde do arquivo
    fazer hash func com o cpf 
    pegar indice do hash
    inserir no hash propriamente dito com o cpf,index,verificador de colisao
inserir na arv abp
*/
}

void inserirHash(hashItem hash[],tipoItem item){
    int ind = hashFunc(item.cpf);
    criaHashItem
    if(hash[ind]!= NULL){
        hash[ind]->prox
    }
}


int EscreverNoArquivo (hashItem *item, FILE *fp,int *pos){
    item->index = *pos;
    fseek(fp, *pos * sizeof(item), 0);
    fwrite(&item,sizeof(item),1,fp);     
    *pos += 1;
} 
