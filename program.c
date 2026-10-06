#include<stdio.h>
#define MAX 100
int n;
float package[MAX], value[MAX], weight[MAX], ratio[MAX], fraction[MAX], capacity;

void enterPackageDetails(){
	int i;
    printf("Enter number of packages: ");
    scanf("%d", &n);
    printf("Enter vehicle capacity: ");
    scanf("%f", &capacity);
    for(i =0; i< n; i++){
        printf("\nPackage %d", i + 1);
        package[i]=i+1;
        printf("\nEnter value: ");
        scanf("%f", &value[i]);
        printf("Enter weight: ");
        scanf("%f", &weight[i]);

        fraction[i] = 0;
        ratio[i] = 0;
    }
}

void displayPackageDetails(){
	int i;
	printf("\nPackage\tValue\tWeight\n");
	for(i=0; i<n; i++){
		printf("\n%0.2f\t%0.2f\t%0.2f", package[i], value[i], weight[i]);
	}
}

void calculateRatio(){
	int i;
	printf("\nPackage\tValue\tWeight\tRatio\n");
	for(i=0; i<n; i++){
		ratio[i]=value[i]/weight[i];
		printf("\n%0.2f\t%0.2f\t%0.2f\t%0.2f", package[i], value[i], weight[i], ratio[i]);
	}
}

void merge(int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = 0;

    float tempValue[MAX];
    float tempWeight[MAX];
    float tempRatio[MAX];
    float tempPackage[MAX];

    while(i <= mid && j <= high){
        if(ratio[i] >= ratio[j]){
            tempValue[k] = value[i];
            tempWeight[k] = weight[i];
            tempRatio[k] = ratio[i];
            tempPackage[k]= package[i];
            i++;
        }
        else{
            tempValue[k] = value[j];
            tempWeight[k] = weight[j];
            tempRatio[k] = ratio[j];
            tempPackage[k]= package[j];
            j++;
        }
        k++;
    }

    while(i <= mid){
        tempValue[k] = value[i];
        tempWeight[k] = weight[i];
        tempRatio[k] = ratio[i];
        tempPackage[k]= package[i];
        i++;
        k++;
    }

    while(j <= high){
        tempValue[k] = value[j];
        tempWeight[k] = weight[j];
        tempRatio[k] = ratio[j];
        tempPackage[k]= package[j];
        j++;
        k++;
    }

    for(i = low, k = 0; i <= high; i++, k++){
        value[i] = tempValue[k];
        weight[i] = tempWeight[k];
        ratio[i] = tempRatio[k];
        package[i] = tempPackage[k];
    }
}

void mergeSort(int low, int high){
    int mid;
    if(low < high){
        mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

void sortPackages(){
	int i;
	
	for(i=0; i<n; i++){
		ratio[i]=value[i]/weight[i];
	}
	
	mergeSort(0, n - 1);
    
    printf("\nPackage\tValue\tWeight\tRatio\n");
	
	for(i=0; i<n; i++){
		printf("\n%0.2f\t%0.2f\t%0.2f\t%0.2f", package[i], value[i], weight[i], ratio[i]);
	}
}

void findMaximumValue(){
	float valueEarned=0, RemCap = capacity;
	int i;
	
	for(i=0; i<n; i++){
		ratio[i] = value[i]/weight[i];
		fraction[i] = 0;
	}
	
	mergeSort(0, n-1);
	
	for(i=0; i<n; i++){
		if(weight[i]<=RemCap){
			RemCap=RemCap-weight[i];
			valueEarned = valueEarned+value[i];
			fraction[i]=1;
		}
		else{
			valueEarned=valueEarned+(ratio[i]*RemCap);
			fraction[i]=RemCap/weight[i];
			RemCap=0;
			break;
		}
	}
	
	printf("\nMaximum Value = %.2f", valueEarned);
	printf("\nTotal Weight Used = %.2f", capacity - RemCap);
}

void displaySelectedPackages(){
	float temp;
	int i, j;
	
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(package[j]>package[j+1]){
				temp=package[j];
				package[j]=package[j+1];
				package[j+1]=temp;
				
				temp=fraction[j];
				fraction[j]=fraction[j+1];
				fraction[j+1]=temp;
			}
		}
	}
	
	printf("\nPackage\tQuantity\n");
	
	for(i=0; i<n; i++){
		printf("\n%0.2f\t%0.2f", package[i], fraction[i]);
	}
}

int main() {
    int choice;
    printf("MENU\n");
    printf("1. Enter Package Details\n");
    printf("2. Display Package Details\n");
    printf("3. Calculate Value/Weight Ratio\n");
    printf("4. Sort Packages by Ratio\n");
    printf("5. Find Maximum Value\n");
    printf("6. Display Selected Packages\n");
    printf("7. Exit\n");
    
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterPackageDetails();
                break;
            case 2:
                displayPackageDetails();
                break;
            case 3:
                calculateRatio();
                break;
            case 4:
                sortPackages();
                break;
            case 5:
                findMaximumValue();
                break;
            case 6:
                displaySelectedPackages();
                break;
            case 7:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice! Please try again later.");
        }
    }
	while (choice != 7);

    return 0;
}
