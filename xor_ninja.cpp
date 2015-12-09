#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int T, N;
    
    vector<long int> storage[2];
    
    vector<long int> input;
    
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        // Get number of input integers N
        cin >> N;
        cin.ignore();
        
  //      cout << "N is " << N << endl;
        input.clear();
        storage[0].clear();
        storage[1].clear();
        long int temp;
   
        long int result = 0;
        
        string line;
        

        std::getline(cin, line);

        
        istringstream lineStream(line);

        // for (int num = 0; num < N; num++) {
        while ( lineStream >> temp ) {
            // Get input in input vector, storage[0] and acculmulate their sum in result
//            cin >> temp;


            input.push_back(temp);
            storage[0].push_back(temp);
            result += temp;
        }


        int read ;
        int write;
        
        for (int i = 0; i < N-1; i++) {
        // For all length of inputs
            
            // For access of storage vectors
            read = i & 1;
            write = (i+1) & 1;
			storage[write].clear();
            
            int kInc = 1;
            int kStart = i + kInc;
           /*cout << "i is " << i << endl;
                        cout << "read is " << read << endl; 
	cout << "read size is " << storage[read].size() << endl;
         */
            for (int j = 0; j < storage[read].size() - 1 ; j++) {
            
      //                  cout << "j is " << j << endl;
            // For elements in read storage array
				if (kStart >= N) {
					kInc++;
					kStart = i + kInc;
//					continue;
				}

				for (int k = kStart; k < N ; k++) {
	//			            cout << "k is " << k << endl;
					long int temp2 = storage[read].at(j) ^ input[k];
					if (k!=N-1)
						storage[write].push_back(temp2);
					result += temp2;
				}
				kStart++;
            
            
            }
            
            
        }

        cout << result % (1000000000+7) << endl;
        
        
    }
    
    return 0;
}

