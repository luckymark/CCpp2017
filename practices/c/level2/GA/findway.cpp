#include<stdio.h>
#include<stdlib.h>
#include<time.h>

	
int table[1000];

int nodenumber=0;

char a[20][20]=		{'*',' ','*','*','*','*','*','*','*','*','*',' *','*','*','*','*','*','*','*','*',
					'*',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*',' ','*',' ','*',
					'*',' ','*',' ','*',' ','*','*','*','*','*',' ','*','*','*','*',' ','*',' ','*',
					'*',' ','*',' ','*',' ',' ',' ','*','*','*',' ','*','*','*','*',' ','*',' ','*',
					'*',' ','*','*','*',' ','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*',
					'*',' ',' ',' ',' ','*','*','*','*',' ','*',' ','*','*',' ','*','*',' ','*','*',
					'*','*','*','*',' ','*','*','*','*',' ','*',' ','*','*',' ','*','*','*','*','*',
					'*',' ','*','*',' ','*','*','*','*',' ','*',' ','*','*',' ',' ',' ',' ','*','*',
					'*',' ',' ','*',' ','*','*','*','*',' ','*',' ','*','*','*','*','*',' ','*','*',
					'*','*',' ','*',' ','*','*',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ','*','*',
					'*','*',' ','*',' ','*','*',' ','*',' ','*','*','*','*','*',' ','*',' ',' ','*',
					'*','*',' ','*',' ','*','*',' ',' ',' ','*','*','*','*','*',' ',' ',' ','*','*',
					'*','*',' ','*',' ','*','*',' ',' ',' ','*','*','*','*','*',' ','*',' ',' ','*',
					'*','*',' ','*',' ','*','*',' ','*',' ','*','*','*','*','*',' ','*','*',' ','*',
					'*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*',' ','*','*',' ','*','*',' ','*',
					'*',' ','*','*',' ','*',' ','*','*',' ','*','*',' ','*','*',' ','*',' ',' ','*',
					'*',' ','*','*',' ','*',' ','*','*',' ',' ',' ',' ',' ',' ',' ','*',' ','*','*',
					'*',' ','*','*',' ','*',' ','*','*',' ','*','*',' ','*','*',' ','*',' ','*','*',
					'*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',
					'*','*','*','*','P','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',
	};


struct node 
{				
	int direction_chance1;
	int direction_chance2;
	int direction_chance3;
	int direction_chance4;
				
	int ad;             //adress;
	int ws;				//adress;
		
	int type ;
	char finalchoes;

	struct node *last;
	struct node *next;
		
	void setsituation(int , int , int , int ); 
		
	void ini(){
		direction_chance1 = 1 ; 
		direction_chance2 = 1 ;
		direction_chance3 = 1 ;
		direction_chance4 = 1 ;
		type = 0 ;
		finalchoes = '\0' ;
	}
};

void node :: setsituation(int chance1, int chance2, int chance3, int chance4)
{
	direction_chance1=chance1;
	direction_chance2=chance2;
	direction_chance3=chance3;
	direction_chance4=chance4;
}

char  judge( node * A )
{
	if( A->direction_chance1 == 1 ){
		A->finalchoes = 'd' ;
		A->direction_chance1 = 0;
	}
	else if( A->direction_chance2 == 1 ){
		A->finalchoes = 's' ;
		A->direction_chance2 = 0;
	}
	else if( A->direction_chance3 == 1 ){
		A->finalchoes = 'a' ;
		A->direction_chance3 = 0;
	}
	else if ( A->direction_chance4 == 1){
		A->finalchoes = 'w' ;
		A->direction_chance4 = 0;
	}
	else A ->finalchoes ='\0';
	return  A->finalchoes;
}

int detect (node *first)
{
	int n=0;
	int i=0;
	int ad=first->ad;
	int ws=first->ws;
	int east , south , west , north ;
	int sum= ws*20 + ad;
	for (int j = 0; j < nodenumber -1  ; j++ ){
		if( table[j] == sum  ){
			return 3;
		}
	}
	if (first->last != NULL){
		if(   ad == 0  || a[ws][ad-1] == '*' || (first->last)->finalchoes == 'd' ||first->direction_chance3 == 0 ){
			west = 0;
			n++;
		}
		else{
			west = 1;
			i++;
		}
		if( ad == 19 || a[ws][ad+1] == '*'   || (first->last)->finalchoes == 'a'||first->direction_chance1 == 0 ){
			east = 0;
			n++;
		}
		else{
			east = 1;
			i++;
		}
		if(  ws == 19 || a[ws+1][ad] == '*' || (first->last)->finalchoes == 'w'||first->direction_chance2==0 ){
			south = 0;
			n++;
		}
		else{
			south = 1;
			i++;
		}
		if(  ws == 0 || a[ws-1][ad] == '*' || (first->last)->finalchoes == 's' ||first->direction_chance4==0){
			north = 0;
			n++;
		}
		else{
			north = 1;
			i++;
		}
	}
	else{
		if( ad == 0  || a[ws][ad-1] == '*'  ||first->direction_chance3 == 0 ){
			west = 0;
			n++;
		}
		else{
			west = 1;
			i++;
		}
		if(  ad == 19 || a[ws][ad+1] == '*' ||first->direction_chance1 == 0 ){
			east = 0;
			n++;
		}
		else{
			east = 1;
			i++;
		}
		if(  ws == 19 || a[ws+1][ad] == '*' ||first->direction_chance2==0 ){
			south = 0;
			n++;
		}
		else{
			south = 1;
			i++;
		}
		if(  ws == 0 || a[ws-1][ad] == '*' ||first->direction_chance4==0 ){
			north = 0;
			n++;
		}
		else{
			north = 1;
			i++;
		}
	}
	
	if(n==4){
		first->setsituation( east , south , west , north );
		return 	3	;	
	}
	
	if(i>=2){
		first->setsituation( east , south , west , north );
		return 2;
	}
	else{
		first->setsituation( east , south , west , north );
		return 1;
	}	
}

node *createnode(node* head1)
{
	 
	
	node *p = (node*) malloc ( sizeof ( node ) );

	p->ini();
	
	head1 -> next = p;

	p -> last =head1; 

	p->next = NULL ;
	
	if( head1 -> finalchoes == 'd' ){
		p -> ws = head1 ->ws ;
		p -> ad = (head1 ->ad ) + 1;
	}

	if( head1 -> finalchoes == 'a'  ){
		p ->ws = head1 ->ws;
		p ->ad = ( head1 ->ad ) -1;
	}
	
	if( head1 -> finalchoes == 'w'  ){
		p ->ws = ( head1 -> ws ) -1;
		p ->ad =  head1 ->ad ;
	}
	
	if( head1 -> finalchoes == 's'  ){
		p ->ws = ( head1 ->ws ) + 1;
		p ->ad =   head1 ->ad ;
	}
	
	table[nodenumber] = ( p->ws ) *20 + ( p->ad ) ;
	nodenumber++;

	return p;
}

int success( node * A)
{
	int sum = ( A->ad ) + ( A->ws)*20 ;
	
	if( sum == 1 ){
		return 1;
	}
	
	else{
		return 0;
	}
}

int main()
{
	node *head;

	head = (node *) malloc( sizeof(node) );

	head->ini();
	
	node *q = head ;

	node *p = head ;

	head->last = NULL ;
	
	head->ws = 19;
	head->ad = 4 ;

	detect( head ) ;

	judge ( head ) ;


	while (1){

		q = createnode( p );
		
		if ( success( q ) == 1 )break;
	
		while( 1  ){
			
			int m;
			m=detect(q);
			
			if( m != 3 )break;
			q = q ->last;
			free(q->next);
			
			table[nodenumber] = -1;
			nodenumber--;
		}	

		judge( q );

		p = q;
	
	}
	
	printf("%d",clock());

	return 0 ;
}
		








