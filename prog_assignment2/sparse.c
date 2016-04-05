#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
        int val;
	int pos;
        struct Node *right;
	struct Node *bottom;
}node;

int main(){
	
	int n;
	scanf("%d",&n);

	if(n==0) return 0;

	////////////////////////////////
	//	Memory Allocation     //
	////////////////////////////////

	node* P1= (node*)calloc(1,sizeof(node));  	//COLUMN head for Matrix 1
	node* Q1= (node*)calloc(1,sizeof(node));       	//ROW head for Matrix 1
	node* P2= (node*)calloc(1,sizeof(node));  	//COLUMN head for Matrix 2
	node* Q2= (node*)calloc(1,sizeof(node));       	//ROW head for Matrix 2

	node* tmp1=P1;      //temp ptrs for traversing
	node* tmp2=Q1;
	node* tmp3=P2;     
	node* tmp4=Q2;

	int i;		//iterator

	//Initialising ROW Head Column and COLUMN Head Row
	for(i=0;i<n-1;i++){
	
		tmp1->right = (node*)calloc(1,sizeof(node));
		tmp1 = tmp1->right;		
		
		tmp2->bottom = (node*)calloc(1,sizeof(node));
		tmp2 = tmp2->bottom;
		
		tmp3->right = (node*)calloc(1,sizeof(node));
		tmp3 = tmp3->right;
		
		tmp4->bottom = (node*)calloc(1,sizeof(node));
		tmp4 = tmp4->bottom;								
	}

//	printf("check1\n");

	int next_mat;               //indicates next matrix
	scanf("%d",&next_mat);

	int row,col,val;

	node* new;         //for new node

	while(next_mat){				//checking for the end of input

       		if(next_mat==1){
			tmp1=P1; tmp2=Q1;
			
			scanf("%d %d %d",&row,&col,&val);	
			
			for(i=0;i<col-1;i++)	tmp1=tmp1->right;		
			while(tmp1->bottom) 	tmp1=tmp1->bottom;		//to reach the current COLUMN position

			for(i=0;i<row-1;i++)	tmp2=tmp2->bottom;
			while(tmp2->right) 	tmp2=tmp2->right;		//to reach the current ROW position

			new = (node*)calloc(1,sizeof(node));

			new->val = val;
			new->pos = col;
			tmp2->right = new;
			tmp1->bottom = new;				
		}

		else{
			tmp3=P2; tmp4=Q2;

			scanf("%d %d %d",&row,&col,&val);	
			
			for(i=0;i<col-1;i++)	tmp3=tmp3->right;		
			while(tmp3->bottom) 	tmp3=tmp3->bottom;		//to reach the current COLUMN position

			for(i=0;i<row-1;i++)	tmp4=tmp4->bottom;
			while(tmp4->right) 	tmp4=tmp4->right;		//to reach the current ROW position

			new = (node*)calloc(1,sizeof(node));

			new->val = val;
			new->pos = row;
			tmp4->right = new;
			tmp3->bottom = new;								
		}

		scanf("%d",&next_mat);		//scanning the next matrix input

	}
//	printf("check2\n");
	int j;
//	printf("check2.5\n");
//	int count;	
	node *tmp; 


	/////////////////////////////////
	// 	PRINT TO CHECK 	       //
	/////////////////////////////////

/*	printf("\n");

	tmp2=Q1;

	if(n==1){
		if(Q1->right) printf("%d",Q1->right->val);
		else printf("0");
	}

	for(i=0;i<n;i++){		
		
		new = tmp2;
		tmp = P1;

		for(j=0;j<n;j++){
			//printf("j=%d\n",j);
			count=0;
			tmp1= tmp;
			while(count<i ){
				 if(tmp1->bottom) tmp1=tmp1->bottom;
				 count++;
			}

			if( tmp2->right && tmp2->right == tmp1->bottom ){
				 printf("%d ",tmp2->right->val);
				 tmp2= tmp2->right;
			}
			else printf("0 ");
			
			tmp = tmp->right;
	
		}
	
		tmp2 = new->bottom;	
		printf("\n");
	
	}
	printf("\n");
//	printf("check3\n");
	tmp4=Q2;
	if(n==1) {
		if(Q2->right) printf("%d",Q2->right->val);
		else printf("0");
	}

	for(i=0;i<n;i++){
	
		new = tmp4;
		tmp= P2;
		for(j=0;j<n;j++){
			count=0;
			tmp3 = tmp;
			while(count<i ){
				 if(tmp3->bottom) tmp3=tmp3->bottom;
				 count++;
			}

		
			if( tmp4->right && tmp4->right == tmp3->bottom ){
				 printf("%d ",tmp4->right->val);
				 tmp4= tmp4->right;
			}
			else printf("0 ");
			
			tmp = tmp->right;
	
		}	
		tmp4 = new->bottom;	
		printf("\n"); 
	}
*/
	/////////////////////////////////
	//       MAIN ALGORITHM        //
	/////////////////////////////////


	tmp=Q1;
	int sum;
//	int col_num;

	for(i=1;i<=n;i++){
		
		if(tmp->right){
			
			tmp3=P2;
			
			for(j=1;j<=n;j++){

				if(tmp3->bottom){

					tmp2= tmp->right;
					new = tmp3->bottom;
					sum=0;

					//////multiply the two lists wrt "pos"/////////
					///////////////////////////////////////////////

					while(tmp2 && new){
						
						if(new->pos < tmp2->pos) new=new->bottom;
						else if(new->pos > tmp2->pos) tmp2=tmp2->right;
						else {
							
							sum = sum + (new->val)*(tmp2->val);
							new=new->bottom;
							tmp2=tmp2->right;
						}						
					}

					if(sum != 0) printf("%d %d %d\n",i,j,sum);		
				}

				tmp3=tmp3->right;							
					
				
			}					
				
		}
		
		tmp = tmp->bottom;			
	}


	///////////////////////////
	//	Free memory	///
	///////////////////////////	
	tmp1=P1; tmp2=Q1; tmp3=P2; tmp4=Q2;

	for (i=0;i<n-1;i++){

		tmp = tmp1->bottom;
		while(tmp){       //free ith column in first matrix
			new = tmp;
			tmp = new ->bottom;
			free(new);		
		}
		tmp= tmp1;	//free ith column head
		tmp1 = tmp->right;
		free(tmp);

		tmp = tmp3->bottom;
		while(tmp){	//free ith column in second matrix
			new = tmp;
			tmp = new ->bottom;
			free(new);		
		}
		tmp= tmp3;	//free ith column head
		tmp3 = tmp->right;
		free(tmp);

		tmp = tmp2;	//free ith row head in first matrix
		tmp2 = tmp->bottom;
		free(tmp);
		
		tmp = tmp4;	//free ith row head in second matrix
		tmp4 = tmp->bottom;
		free(tmp); 
	
	}

	return 0;	
}

