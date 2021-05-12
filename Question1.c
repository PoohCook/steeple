void foo(float A[6][6],float b[6],float c[6]){
    int i,j;
    for(i=0;i<6;i++){
        c[i] = 0.0f;
        for(j=0;j<6;j++){
            c[i] += A[i][j] * b[j];
    } }
}

int main(){
    float F[6][6];
    float x[6]; ...
    foo(F, x, x); ...
    return 0; 
    }

In no particular order

1. The values being passed into foo are pass by value so there is a lot of copy work done to the stack for every call (8*6*4= 192 bytes )

2. foo doesn't actually return any values...  It appears to think it is returning them in c but since that is a pass by value, it's 
really just scribbling on stack that will be lost upon return.

3. it bizarely is passing x both to an input and the imagined output parameter, which would hurt a reader's brain to think about if not 
for the fact that all data out is destined for the bit bucket.

4. The function foo is a great example of poor code style in general...  the variables are poorely named and little consideration is given for 
the unlucky reader of the code.

5. There are too many 6's in all of that a #define MY_ARRAY_SIZE 6 would help prevent future changes ot size from walking of the end of the arrays...