#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NOKTA 100

typedef struct {
    float x;
    float y;
} Nokta;

float uzaklik_hesapla(Nokta n1, Nokta n2) {
    float dx = n1.x - n2.x;
    float dy = n1.y - n2.y;
    return sqrt(dx * dx + dy * dy);
}

void aglomeratif_kumelenme(Nokta noktalar[], int n) {
    int kumeler[MAX_NOKTA];
    
    for (int i = 0; i < n; i++) {
        kumeler[i] = i;
    }
    
    for (int iter = 0; iter < n - 1; iter++) {
        float min_uzaklik = INFINITY;
        int min_i, min_j;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (kumeler[i] != kumeler[j]) {
                    float uzaklik = uzaklik_hesapla(noktalar[i], noktalar[j]);
                    if (uzaklik < min_uzaklik) {
                        min_uzaklik = uzaklik;
                        min_i = i;
                        min_j = j;
                    }
                }
            }
        }
        
        for (int k = 0; k < n; k++) {
            if (kumeler[k] == kumeler[min_i] || kumeler[k] == kumeler[min_j]) {
                kumeler[k] = n + iter;
            }
        }
        
        printf("Iterasyon %d: Kume %d ve %d birlestirildi\n", iter+1, min_i+1, min_j+1);
    }
}

int main() {
    Nokta noktalar[MAX_NOKTA];
    int n;
    
    printf("Nokta sayisini girin: ");
    scanf("%d", &n);
    
    printf("Her noktanin koordinatlarini girin:\n");
    for (int i = 0; i < n; i++) {
        printf("Nokta %d: ", i+1);
        scanf("%f %f", &noktalar[i].x, &noktalar[i].y);
    }
    
    aglomeratif_kumelenme(noktalar, n);
    
    return 0;
}

