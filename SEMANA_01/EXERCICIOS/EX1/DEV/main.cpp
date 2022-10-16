#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <algorithm>

using namespace std;

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor
int converteSensor(float valor, float min, float max){
	float medida = (valor - min) / (max - min) * 100;
	if (medida > 100){
		return 100;
	} else if (medida < 0){
		return 0;
	} else {
		return medida;
	}
}

// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor
int leSensor() {
	int valor;
	cout << "Digite o valor: " << endl;
	cin >> valor;
	return valor;
}

// 3 - Faça uma função que armazena uma medida inteira qualquer 
// em um vetor fornecido. Note que como C não possui vetores 
// nativos da linguagem, lembre-se que você precisa passar o 
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em 
// uma área de memória fora do vetor
int armazenaMedida(int *valores, int tamanho, int ultimaPosicao, int valor) {
	int posicaoAtual = ultimaPosicao++;

	if(posicaoAtual < tamanho){
		valores[posicaoAtual] = valor;
	} else {
		throw std::invalid_argument("Posição inválida");
	}

	return posicaoAtual;
}

// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.
std::pair<std::string, int> direcaoMaiorDistancia(int distancias[4]) {

	int maior = distancias[0];
	int maiorEndereco = 0;

	for (int i = 0; i < 4; i++) {
		if (distancias[i] > maior) {
			maior = distancias[i];
			maiorEndereco = i;
		}
	}

	std::string maiorDirecao;
	switch (maiorEndereco) {
		case 0:
			maiorDirecao =  "Direita";
		break;
		case 1:
			maiorDirecao =  "Esquerda";
		break;
		case 2:
			maiorDirecao =  "Frente";
		break;
		case 3:
			maiorDirecao =  "Trás";
		break;
	}

	return std::pair<std::string, int>(maiorDirecao, maior);
}



// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso
bool leComando() {
	char resposta;
	cout << "Deseja continuar o mapeamento?(S/N)";
	cin >> resposta;
	if(resposta == 'S' || resposta == 's'){
		return true;
	} else if (resposta == 'N' || resposta == 'n'){
		return false;
	}
}

// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas
int dirige(int *v,int maxv){
	int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;		
	while(dirigindo){		
		std::cout << "Direita: ";
		int medida = leSensor();
		medida = converteSensor(medida, 0, 830);
		posAtualVetor = armazenaMedida(vetorMov, maxVetor, posAtualVetor, medida);
		posAtualVetor++;

		std::cout << "Esquerda: ";
		medida = leSensor();
		medida = converteSensor(medida, 0, 830);
		posAtualVetor = armazenaMedida(vetorMov, maxVetor, posAtualVetor, medida);
		posAtualVetor++;

		std::cout << "Frente: ";
		medida = leSensor();
		medida = converteSensor(medida, 0, 830);
		posAtualVetor = armazenaMedida(vetorMov, maxVetor, posAtualVetor, medida);
		posAtualVetor++;

		std::cout << "Trás: ";
		medida = leSensor();
		medida = converteSensor(medida, 0, 830);
		posAtualVetor = armazenaMedida(vetorMov, maxVetor, posAtualVetor, medida);
		posAtualVetor++;

		dirigindo = leComando();		
	}
	return posAtualVetor;
} 


//O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
//do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
//na maior distância a cada movimento
void percorre(int *v,int tamPercorrido){		
	int *vetorMov = v;

	for(int i = 0; i < tamPercorrido; i+=4) {
		std::pair<std::string, int> distancia = direcaoMaiorDistancia(&(vetorMov[i]));
		std::string direcao = distancia.first;
		int valor = distancia.second;

		printf("Movimentando para %s distancia = %i%%\n", direcao.c_str(), valor);
	}
}

int main(int argc, char** argv) {
	const int maxVetor = 100;
	int vetorMov[maxVetor * 4];
	int posAtualVet = 0;

	posAtualVet = dirige(vetorMov, maxVetor);
	percorre(vetorMov, posAtualVet);

	return 0;
}
