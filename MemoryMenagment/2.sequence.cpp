#include <iostream>
using namespace std;

int main()
{
        
    int length;
    cin >> length;
    
    int numbers[length];
    
    cout << "Enter numbers: "<< endl;
    for(int i = 0; i < length; i++){
        cin >> numbers[i];
    }

    int beginning = 0;
    int end = 0;
    int lengthArr = 0;
    for(int i = 0; i < length; i++){
        int tempLength = 0;
        
        int tempEnd = 0;
        for(int j = i; j < length; j++){
            if(numbers[i] == numbers[j]){
                tempLength++;   
            }else{
                tempEnd = j;
                break;
            }
        }
        if(lengthArr < tempLength){
            beginning = i;
            end = tempEnd;
            lengthArr = tempLength;
        }
    }
    
    for(int i = beginning; i < end; i++){
        cout << numbers[i] << endl;   
    }
}