#include <iostream>
#include <algorithm>

using namespace std;

struct Stu {
    int num;
    int tim;
};

int compare(Stu a, Stu b) {
    if(a.num!=b.num) {
        return a.num>b.num;
    } else {
        return a.tim<b.tim;
    }
}

int main() {

    int N, G, S, C, M;
    scanf("%d %d %d %d %d", &N, &G, &S, &C, &M);
    while(N) {
        Stu stu[N];
        int output = 0;
        for(int i=0; i<N; i++) {
            int corNum, hh, mm, ss;
            scanf("%d %d:%d:%d", &stu[i].num, &hh, &mm, &ss);
            stu[i].tim = hh*3600 + mm*60 + ss;
            if(i==M-1) {
                output = stu[i].tim;
            }
        }
        sort(stu, stu+N, compare);

        for(int i=0; i<N; i++) {
            if(stu[i].tim == output) {
                if(i<G) {
                    printf("Accepted today? I've got a golden medal :)\n");
                } else if(i<G+S) {
                    printf("Accepted today? I've got a silver medal :)\n");
                } else if(i<G+S+C) {
                    printf("Accepted today? I've got a copper medal :)\n");
                } else {
                    printf("Accepted today? I've got an honor mentioned :)\n");
                }
            }
        }

        scanf("%d %d %d %d %d", &N, &G, &S, &C, &M);
    }

    return 0;
}
