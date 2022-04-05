#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

    	int n,m;

        cin >> n >> m;
        int **arr;
        int **answer;

        arr = new int *[n];
        answer = new int *[n];

        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[m];
            answer[i] = new int[m];
        }
		
		for (int i = 0; i < n; i++) {
			string s;
            cin >> s;
            for (int j = 0; j < s.length(); j++) {
				if(s.substr(j,1)=="W") {
					arr[i][j]=0;
					answer[i][j]=0;
				}else {
					arr[i][j]=1;
					answer[i][j]=1;
				}
			}
		}

        int min1 = INT_MAX;
        int min2 = INT_MAX;

        int r=n-8+1;
		int c=m-8+1;
		int sum=0;
		int basenum;
		int sp;
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				basenum=arr[i][j];
				sp=1-basenum;
				sum=0;
				for (int k = 0; k < 8; k++) {
					for (int l = 0; l < 8; l++) {
						if(k==0 && l==0 && basenum==arr[i][j]) continue;
						if(arr[i+k][j+l]==sp) {
							sp=1-sp;
						}else {
							sum++;
							arr[i+k][j+l]=sp;
							sp=1-sp;
						}
					}
					sp=1-arr[i+k][j];
				}
				if(min1>sum) min1=sum;
				
				for (int w = 0; w < n; w++) {
					for (int v = 0; v < m; v++) {
						arr[w][v]=answer[w][v];
					}
				}
			}
		}
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				basenum=1-arr[i][j];
				sp=1-basenum;
				sum=0;
				for (int k = 0; k < 8; k++) {
					for (int l = 0; l < 8; l++) {
						if(k==0 && l==0) {
							arr[i][j]=basenum;
							sum++;
							continue;
						}
						if(arr[i+k][j+l]==sp) {
							sp=1-sp;
						}else {
							sum++;
							arr[i+k][j+l]=sp;
							sp=1-sp;
						}
					}
					sp=1-arr[i+k][j];
				}
				if(min2>sum) min2=sum;
				
				for (int w = 0; w < n; w++) {
					for (int v = 0; v < m; v++) {
						arr[w][v]=answer[w][v];
					}
				}
			}
		}

        cout << min({min1, min2}) << endl;
}