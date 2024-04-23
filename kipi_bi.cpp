#include<iostream>
#include<vector>
using namespace std;

int main(){
    string str;
    cin >> str;
    sort(begin(str),end(str),[&](char &a, char &b) -> bool{
        if(isalpha(a) && isdigit(b)){
            return true;
        }
        else if (isalpha(b) && isdigit(a)) {
            return false;
        }
        else if(isalpha(a) && isalpha(b)){
            int orda = a-'a', ordb = b-'a';
            if((orda%2 ^ ordb%2 == 0)){
                return a < b;
            }
            return (orda%2 == 1 && ordb%2 == 0);
        }
        else {
            int orda = a-'0', ordb = b-'0';
            if((orda%2 ^ ordb%2 == 0)){
                return a < b;
            }
            return (orda%2 == 1 && ordb%2 == 0);
        }
        return a < b;
    });
    cout<<str<<endl;
}

/*

#import
#include
int main(){
    -(NSArray *) arrayBubbleSort: (NSArray *) targetArray{
        NSMutableArray *resultArray = [targetArray mutableCopy];
        for (int s = 0; s < resultArray.count; s++){
            for (int e = 0; e < resultArray.count; e++) {
                if ([resultArray[s] intValue] < [resultArray[e] intValue]){
                    [resultArray exchangeObjectAtIndex:k withObjectAt Index: 1];
                }
            }
        }
        return resultArray;
    }
}
*/ 