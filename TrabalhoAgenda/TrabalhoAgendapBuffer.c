#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *Menu( void *pBuffer );
void *AdicionarPessoa( void *pBuffer );
void *RemoverPessoa( void *pBuffer );
void BuscarPessoa( void *pBuffer );
void ListarPessoas( void *pBuffer );

int main() {
	void *pBuffer;

	pBuffer = malloc( 6 * sizeof( int ) + 50 * sizeof( char ) ); //6 ints + 50 char
	*( int * )( pBuffer ) = 0; //opcoes do menu
	*( int * )( pBuffer + sizeof( int ) ) = 0;  //contador de pessoas
	*( int * )( pBuffer + 2 * sizeof( int ) ) = ( 6 * sizeof( int ) ) + ( 50 * sizeof( char ) );  //tamanho total do buffer
	*( int * )( pBuffer + 3 * sizeof( int ) ) = 0; //loops
	*( int * )( pBuffer + 4 * sizeof( int ) ) = 0; //loops
	*( int * )( pBuffer + 5 * sizeof( int ) ) = 0; //loops

	while ( 1 ) {
		pBuffer = Menu ( pBuffer );
	}

	return 0;
}

void *Menu ( void *pBuffer ){
	do {
		printf( "\n=================================" );
printf( "\n            AGENDA" );
printf( "\n=================================" );
printf( "\n[1] Adicionar Pessoa" );
printf( "\n[2] Remover Pessoa" );
printf( "\n[3] Buscar Pessoa" );
printf( "\n[4] Listar Pessoas" );
printf( "\n[5] Sair" );
printf( "\n=================================" );
printf( "\nOpcao: " );
		scanf( "%d", ( int * )pBuffer ); //opcao do menu no comeco do buffer
	} while ( *( int * )pBuffer <= 0 || *( int * )pBuffer > 5 );
	switch ( *( int * )pBuffer ) { //switch case do comeco do buffer
		case 1:
			pBuffer = AdicionarPessoa ( pBuffer );
			break;
		case 2:
			pBuffer = RemoverPessoa ( pBuffer );
			break;
		case 3:
			BuscarPessoa ( pBuffer );
			break;
		case 4:
			ListarPessoas ( pBuffer );
			break;
		case 5:
			free( pBuffer );
			exit(0);
			break;
		default:
			break;
		}
	return pBuffer;
}

void *AdicionarPessoa ( void *pBuffer ) {
	printf( "Nome: " );
	getchar(); 
	fgets( ( char * )pBuffer + ( 6 * sizeof( int ) ), 50, stdin ); //le nome digitado
	*( ( char * )pBuffer + ( 6 * sizeof( int ) ) + strcspn( ( char * )pBuffer + ( 6 * sizeof( int ) ), "\n" ) ) = '\0'; //encontra \n e substitui por 0

	pBuffer = realloc( pBuffer, ( *( int * )( pBuffer + 2 * sizeof( int ) ) + ( strlen( ( char * )pBuffer + ( 6 * sizeof( int ) ) ) ) + 1 ) ); //aumenta buffer baseado no nome
	strcpy( ( char * )pBuffer + *( int * )( pBuffer + 2 * sizeof( int ) ), ( char * )pBuffer + ( 6 * sizeof( int ) ) ); //rascunho -> area definitiva
	*( int * )( pBuffer + 2 * sizeof( int ) ) = ( *( int * )( pBuffer + 2 * sizeof( int ) ) + ( strlen( ( char * )pBuffer + ( 6 * sizeof( int ) ) ) ) + 1 ); 

	printf( "idade: " ); //mesma logica do nome porem calcula onde termina o nome e escreve depois
	pBuffer = realloc( pBuffer, ( *( int * )( pBuffer + 2 * sizeof( int ) ) ) + sizeof( int ) );
	scanf( "%d", ( int * )( ( char * )pBuffer + *( int * )( pBuffer + 2 * sizeof( int ) ) ) );
	*( int * )( pBuffer + 2 * sizeof( int ) ) = ( *( int * )( pBuffer + 2 * sizeof( int ) ) + sizeof( int ) ); 

	printf( "Email: " ); //mesma logica do nome porem calcula onde termina a idade e escreve depois
	getchar(); 
	fgets( ( char * )pBuffer + ( 6 * sizeof( int ) ), 50, stdin );
	*( ( char * )pBuffer + ( 6 * sizeof( int ) ) + strcspn( ( char * )pBuffer + ( 6 * sizeof( int ) ), "\n" ) ) = '\0'; 

	pBuffer = realloc( pBuffer, ( *( int * )( pBuffer + 2 * sizeof( int ) ) + ( strlen( ( char * )pBuffer + ( 6 * sizeof( int ) ) ) ) + 1 ) );
	strcpy( ( char * )pBuffer + *( int * )( pBuffer + 2 * sizeof( int ) ), ( char * )pBuffer + ( 6 * sizeof( int ) ) ); 
	*( int * )( pBuffer + 2 * sizeof( int ) ) = ( *( int * )( pBuffer + 2 * sizeof( int ) ) + ( strlen( ( char * )pBuffer + ( 6 * sizeof( int ) ) ) ) + 1 ); 

	*( int * )( pBuffer + sizeof( int ) ) += 1; // aumenta contador de pessoas

	printf( "\nPessoa adicionada com sucesso!" );

	return pBuffer; 
}

void BuscarPessoa ( void *pBuffer ) {
	*( int * )( pBuffer + 3 * sizeof( int ) ) = ( 6 * sizeof( int ) ) + ( 50 * sizeof( char ) ); //inicializa o ponteiro de leitura
	*( int * )( pBuffer + 4 * sizeof( int ) ) = 0; //zera contador do loop

	printf( "Nome: " );
	getchar(); 
	fgets( ( char * )pBuffer + ( 6 * sizeof( int ) ), 50, stdin ); //nome vai pro rascunho
	*( ( char * )pBuffer + ( 6 * sizeof( int ) ) + strcspn( ( char * )pBuffer + ( 6 * sizeof( int ) ), "\n" ) ) = '\0'; 

	while ( *( int * )( pBuffer + 4 * sizeof( int ) ) < *( int * )( pBuffer + sizeof( int ) ) ) { //loop percorre todas as pessoas
		if ( strcmp( ( char * )pBuffer + ( 6 * sizeof( int ) ), ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) ) == 0 ) { //compara nome digitado com atual
			printf( "\n" );

			printf( "\nNome: %s", ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) );

			printf( "\nIdade: %d", *( int * )( ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) + strlen( ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) ) + 1 ) ); 

			printf( "\nEmail: %s\n", ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) + strlen( ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) ) + 1 + sizeof( int ) ); 
		}

		*( int * )( pBuffer + 3 * sizeof( int ) ) += strlen( ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) ) + 1;  //pula nome

		*( int * )( pBuffer + 3 * sizeof( int ) ) += sizeof( int );  //pula idade

		*( int * )( pBuffer + 3 * sizeof( int ) ) += strlen( ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) ) + 1;  //pula email

		*( int * )( pBuffer + 4 * sizeof( int ) ) += 1; //c++
	}
}

void ListarPessoas ( void *pBuffer ) {
	*( int * )( pBuffer + 3 * sizeof( int ) ) = ( 6 * sizeof( int ) ) + ( 50 * sizeof( char ) ); 
	*( int * )( pBuffer + 4 * sizeof( int ) ) = 0; 

	printf( "\n------------------------------------------------------" );
	while ( *( int * )( pBuffer + 4 * sizeof( int ) ) < *( int * )( pBuffer + sizeof( int ) ) ) { //ate aqui igual o buscar
		printf( "\nNome: %s", ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) ); //printa nome
		*( int * )( pBuffer + 3 * sizeof( int ) ) += strlen( ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) ) + 1;  //avanca memoria pulando o nome

		printf( "\nIdade %d", *( int * )( ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) ) ); //igual nome
		*( int * )( pBuffer + 3 * sizeof( int ) ) += sizeof( int ); 

		printf( "\nEmail: %s", ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) ); //igual nome
		*( int * )( pBuffer + 3 * sizeof( int ) ) += strlen( ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) ) + 1;  
		printf( "\n------------------------------------------------------" );

		*( int * )( pBuffer + 4 * sizeof( int ) ) += 1; // igual buscar
	}
}

void *RemoverPessoa ( void *pBuffer ) {
	*( int * )( pBuffer + 3 * sizeof( int ) ) = ( 6 * sizeof( int ) ) + ( 50 * sizeof( char ) ); //inicializando ponteiro de leitura no comeco dos dados
	*( int * )( pBuffer + 4 * sizeof( int ) ) = 0; //controla o loop 
	*( int * )( pBuffer + 5 * sizeof( int ) ) = 0; //armazena tamanho da pessoa

	printf( "Nome: " );
	getchar(); 
	fgets( ( char * )pBuffer + ( 6 * sizeof( int ) ), 50, stdin ); //manda nome pro rascunho
	*( ( char * )pBuffer + ( 6 * sizeof( int ) ) + strcspn( ( char * )pBuffer + ( 6 * sizeof( int ) ), "\n" ) ) = '\0'; 

	while ( *( int * )( pBuffer + 4 * sizeof( int ) ) < *( int * )( pBuffer + sizeof( int ) ) ) {
		if ( strcmp( ( char * )pBuffer + ( 6 * sizeof( int ) ), ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) ) == 0 ) { //checa se encontra o nome
			*( int * )( pBuffer + 5 * sizeof( int ) ) += strlen( ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) ) + 1; //add tamanho do nome

			*( int * )( pBuffer + 5 * sizeof( int ) ) += sizeof( int ); //tamanho da idade

			*( int * )( pBuffer + 5 * sizeof( int ) ) += strlen( ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) + *( int * )( pBuffer + 5 * sizeof( int ) ) ) + 1; //add tamanho do email

			*( int * )( pBuffer + 4 * sizeof( int ) ) = *( int * )( pBuffer + 3 * sizeof( int ) ) + *( int * )( pBuffer + 5 * sizeof( int ) ); //calcula onde termina a pessoa

			
			

			
			while ( *( int * )( pBuffer + 4 * sizeof( int ) ) < *( int * )( pBuffer + 2 * sizeof( int ) ) ) { //percorre depois da pessoa
				*( ( char * )pBuffer + ( *( int * )( pBuffer + 4 * sizeof( int ) ) - *( int * )( pBuffer + 5 * sizeof( int ) ) ) ) = *( ( char * )pBuffer + *( int * )( pBuffer + 4 * sizeof( int ) ) );
				

				*( int * )( pBuffer + 4 * sizeof( int ) ) += 1; 
			}

			*( int * )( pBuffer + 2 * sizeof( int ) ) -= *( int * )( pBuffer + 5 * sizeof( int ) ); //atualiza tamanho total
			*( int * )( pBuffer + sizeof( int ) ) -= 1; //atualiza contador de pessoas

			pBuffer = realloc( pBuffer, *( int * )( pBuffer + 2 * sizeof( int ) ) );

			printf( "\nPessoa removida com sucesso!" );

			return pBuffer;
		}

		*( int * )( pBuffer + 3 * sizeof( int ) ) += strlen( ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) ) + 1;  

		*( int * )( pBuffer + 3 * sizeof( int ) ) += sizeof( int ); 

		*( int * )( pBuffer + 3 * sizeof( int ) ) += strlen( ( char * )pBuffer + *( int * )( pBuffer + 3 * sizeof( int ) ) ) + 1;  

		*( int * )( pBuffer + 4 * sizeof( int ) ) += 1;
	}
	return pBuffer;
}