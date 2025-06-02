
int hashFunc(long int cpf){
    int ind = (cpf * 31) % tam;
    return ind;
}

void criaHashItem(hashItem * itemHash, tipoItem item, unsigned int index){
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
