int hashFunc(item item, const tam){
    int ind = (item.cpf * 31) % tam;
    return ind;
}

void inserir(FILE * arq, ABP * arv, hashItem hash[]){

}
