#include<stdio.h>
#include<stdlib.h>

	
int table[1000];
int itable =0;

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
		
		char judge(node *);

//		int judge_end( node* );
};

void node :: setsituation(int chance1, int chance2, int chance3, int chance4)
{
	direction_chance1=chance1;
	direction_chance2=chance2;
	direction_chance3=chance3;
	direction_chance4=chance4;
}

char node ::judge( node * A )
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
	for (int j = 0; j <= itable ; j++ ){
		if( table[j] == ws *20 +ad  ){
			return 3;
		}
	}
	if (first->last != NULL){
		if(   ad == 0  || a[ws][ad-1] == '*' || (first->last)->finalchoes == 'd'  ){
			west = 0;
			n++;
		}
		else{
			west = 1;
			i++;
		}
		if(   ad == 19 || a[ws][ad+1] == '*'   || (first->last)->finalchoes == 'a' ){
			east = 0;
			n++;
		}
		else{
			east = 1;
			i++;
		}
		if(  ws == 19 || a[ws+1][ad] == '*' || (first->last)->finalchoes == 'w' ){
			south = 0;
			n++;
		}
		else{
			south = 1;
			i++;
		}
		if(  ws == 0 || a[ws-1][ad] == '*' || (first->last)->finalchoes == 's' ){
			north = 0;
			n++;
		}
		else{
			north = 1;
			i++;
		}
	}
	else{
		if( ad == 0  || a[ws][ad-1] == '*'   ){
			west = 0;
			n++;
		}
		else{
			west = 1;
			i++;
		}
		if(  ad == 19 || a[ws][ad+1] == '*'  ){
			east = 0;
			n++;
		}
		else{
			east = 1;
			i++;
		}
		if(  ws == 19 || a[ws+1][ad] == '*'  ){
			south = 0;
			n++;
		}
		else{
			south = 1;
			i++;
		}
		if(  ws == 0 || a[ws-1][ad] == '*'  ){
			north = 0;
			n++;
		}
		else{
			north = 1;
			i++;
		}
	}
	
	if(n==4){
		return 	3	;	
	}
	
	else{
		first->setsituation( east , south , west , north );
		return 1;
	}

	if(i>=2){
		return 2;
	}
}

node *createnode(node* last)
{
	char chose = 0; 
	
	node *p = (node*) malloc ( sizeof ( node ) );

	nodenumber++;
	
	last -> next = p;

	p -> last =last; 

	chose = last -> finalchoes;
	
	if( last -> finalchoes == 'd' ){
		p -> ws = last ->ws ;
		p -> ad = (last ->ad ) + 1;
	}

	if( last -> finalchoes == 'a'  ){
		p ->ws = last ->ws;
		p ->ad = ( last ->ad ) -1;
	}
	
	if( last -> finalchoes == 'w'  ){
		p ->ws = ( last -> ws ) -1;
		p ->ad =  last ->ad ;
	}
	
	if( last -> finalchoes == 's'  ){
		p ->ws = ( last ->ws ) + 1;
		p ->ad =   last ->ad ;
	}

	return last;
}

void success( node * A)
{
	( A->ad ) + ( A-  


}


int main()
{
	int status=0;
	node *q = NULL ;
	
	node *lead =(node*) malloc ( sizeof(node) );
	lead->ini();
	node *p = lead;
	lead->ad=4;
	lead->ws=19;
	lead->last=NULL;
	detect(lead);
	lead->judge(lead);
	
	while(1){
		while( detect(p) == 3  ){
			p = p ->last ;
			free( p ->next ) ;
			nodenumber--;
		}
		
		q = createnode(p);
	
		q->ini();

		status=detect(q);
	
		if( status == 3 ){
			free(q);
			nodenumber--;
			if(p -> finalchoes== 'd' ){
				p->direction_chance1 = 0 ;
			}
			else if ( p -> finalchoes== 's' ){
				p ->direction_chance2 = 0;
			}
			else if ( p -> finalchoes== 'a' ){
				p ->direction_chance3 = 0;
			}
			else if ( p -> finalchoes== 'w'){
				p ->direction_chance4 = 0 ;
			}
			p ->judge( p ) ;
		
			continue;
		}

		else if ( status == 2 ){
			q ->type =1;
			table[itable]= ( q->ws ) * 20 + ( q->ad ) ;
			itable++;
		}
		
		p = q ;
	printf("%d ",nodenumber);
	}
	
	return 0 ;
}
		
			
	

	










