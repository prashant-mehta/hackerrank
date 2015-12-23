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
    vector<int> counter[2];
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
        
        counter[0].clear();
        counter[1].clear();        
        
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
        storage[0].pop_back();



		for (int i = N-1; i > 0; i--) {
			counter[0].push_back(i);
		}

        int read ;
        int write;
        
        
        
        
        for (int i = 0; i < N-1; i++) {
        // For all length of inputs
            
            // For access of storage vectors
            read = i & 1;
            write = (i+1) & 1;
			storage[write].clear();
			counter[write].clear();
            
			int curr_read_size = storage[read].size();
           /*cout << "i is " << i << endl;
                        cout << "read is " << read << endl; 
	cout << "read size is " << storage[read].size() << endl;
         */
            for (int j = 0; j <= curr_read_size - 1 ; j++) {
            	
            	
            	for ( int k = N-counter[read].at(j); k < N; k++ ) {
					long int temp2 = storage[read].at(j) ^ input[k];
					
			//		cout << i << "\t" << j << "\t" << N-1-k << endl;
					result += temp2;
            		if (k != N-1) {
						storage[write].push_back(temp2);
			//			cout << "Pushing" << N-1-k  << endl;
						counter[write].push_back(N-1-k);
            		}
            	
            	}
            	
				            
            
            }
            
            
        }

        cout << result % (1000000000+7) << endl;
        
        
    }
    
    return 0;
}

