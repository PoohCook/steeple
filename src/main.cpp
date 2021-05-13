#include <iostream>

using namespace std;

void foo(float A[6][6],float b[6], double result[6], int size){
      int i,j;
      for(i=0;i<size;i++){		
            result[i] = 0.0f; 
            for(j=0;j<size;j++){			
                  result[i] += ((double)A[i][j]) * ((double)b[j]); 
            } 
      } 
} 

#define dimension   6
int main(){
    	float F[dimension][dimension]= {
            {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f},
            {0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f},
            {0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 4.0f},
            {0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f},
            {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f},
            {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
      };
	float x[dimension] = {0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f}; 	
      double output[dimension] = {0.0f};

      foo(F, x, output, dimension); 

      for( int i=0 ; i<dimension ; i++){
            cout << output[i] << ", ";
      }

      cout << endl;

	return 0; 
} 
