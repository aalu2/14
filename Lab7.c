//Answer of 1
#include <stdio.h>
int main()
{
  int m, n, p, q, i, j, k, sum = 0;
  int first[10][10], second[10][10], product[10][10];
  
  printf("Enter the number of rows and columns for first matrix (m,n): ");
  scanf("%d%d", &m, &n);
  
  printf("Enter the number of rows and columns for second matrix (p,q): ");
  scanf("%d%d", &p, &q);
  
  if (n != p)
  {
    printf("Matrices multiplication is not possible\n");
    return 0;
  }

  printf("Enter numbers for each element in first array: ");
  
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &first[i][j]);
      
  printf("Enter numbers for each element in second array: ");
  
  for (i = 0; i < p; i++)
    for (j = 0; j < q; j++)
      scanf("%d", &second[i][j]);

  // Multiplication logic
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < q; j++)
    {
      for (k = 0; k < p; k++)
      {
        sum += first[i][k] * second[k][j];
      }
      product[i][j] = sum;
      sum = 0;
    }
  }
  
  printf("Result after multiplication of two arrays:\n");
  
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < q; j++)
    {
      printf("  %d", product[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}



//Answer of 2
#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int a, b;
    
    printf("Enter two numbers a & b: ");
    scanf("%d %d", &a, &b);

    printf("Before swapping, a = %d, b = %d\n", a, b);
    
    swap(&a, &b);

    printf("After swapping by pointer, a = %d, b = %d\n", a, b);

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Answer of 3
#include <stdio.h>
int main() {
char input_string[100];
int ch;
printf("Enter any string: ");
while ((ch = getchar()) != '\n' && ch != EOF) {
putchar(ch);
}
putchar('\n');

return(0);
}

//Answer of 4
#include <stdio.h>

int factorial(int n);

int main() {
    int n, fact;

    printf("Enter a number: ");
    scanf("%d", &n);

    fact = factorial(n);

    printf("Factorial=%d", fact);

    return 0;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}


//Answer of 5
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], rev[100];
    int i, len, flag = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    // copy the string in reverse order
    for (i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0'; // add null terminator at the end of reversed string

    // compare original string with reversed string
    for (i = 0; i < len; i++) {
        if (str[i] != rev[i]) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("Result: not a palindrome string\n");
    } else {
        printf("Result: yes, it is a palindrome string\n");
    }

    return 0;
}

//Answer of 6
#include <stdio.h>

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int result[], int *nRes) {
    int i, j;
    *nRes = 0;
    // Copy first array to result
    for (i = 0; i < n1; i++) {
        result[*nRes] = arr1[i];
        (*nRes)++;
    }
    // Add second array elements to result if not already present
    for (i = 0; i < n2; i++) {
        for (j = 0; j < n1; j++) {
            if (arr2[i] == arr1[j]) {
                break;
            }
        }
        if (j == n1) {
            result[*nRes] = arr2[i];
            (*nRes)++;
        }
    }
}

int main() {
    int arr1[100], arr2[100], result[200];
    int n1, n2, nRes, i;
    printf("Enter the size of 1st array: ");
    scanf("%d", &n1);
    printf("Enter each element: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the size of 2nd array: ");
    scanf("%d", &n2);
    printf("Enter each element: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    mergeArrays(arr1, n1, arr2, n2, result, &nRes);
    printf("Result of merging: ");
    for (i = 0; i < nRes; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}

//Answer of 7
#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the binomial coefficient of n and k
int binomial_coefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to print the binomial coefficient table up to a given order
void print_binomial_table(int order) {
    for (int n = 0; n <= order; n++) {
        for (int k = 0; k <= n; k++) {
            printf("%d ", binomial_coefficient(n, k));
        }
        printf("\n");
    }
}

int main() {
    int order;

    printf("Enter the order of binomial power expression: ");
    scanf("%d", &order);

    print_binomial_table(order);

    return 0;
}

//Answer of 8
#include <stdio.h>
int main()
{
    int arr[100], n, i, j, k;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter numbers for each element: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n;)
        {
            if (arr[j] == arr[i])
            {
                for (k = j; k < n; k++)
                    arr[k] = arr[k + 1];
                n--;
            }
            else
                j++;
        }
    }
    printf("Results of removing duplicate: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

//Answer of 9
#include <stdio.h>

int remove_duplicates(int arr[], int n) {
    int i, j, index = 0;
    for (i = 0; i < n; i++) {
        int flag = 0;
        for (j = 0; j < index; j++) {
            if (arr[i] == arr[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            arr[index] = arr[i];
            index++;
        }
    }
    return index;
}

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int kth_smallest_element(int arr[], int n, int k) {
    bubble_sort(arr, n);
    int new_size = remove_duplicates(arr, n);
    if (k > new_size) {
        return -1;
    }
    return arr[k-1];
}

int main() {
    int n, k;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);
    int result = kth_smallest_element(arr, n, k);
    if (result == -1) {
        printf("Invalid value of k");
    } else {
        printf("%dth smallest element is %d", k, result);
    }
    return 0;
}


//Answer of 10
#include <stdio.h>
#include <math.h>

float calculateSD(float data[], int n) {
    float sum = 0.0, mean, standardDeviation = 0.0;

    int i;

    for (i = 0; i < n; ++i) {
        sum += data[i];
    }

    mean = sum / n;

    for (i = 0; i < n; ++i) {
        standardDeviation += pow(data[i] - mean, 2);
    }

    return sqrt(standardDeviation / n);
}

int main() {
    int n, i;
    float data[100];

    printf("Enter size of the array:");
    scanf("%d", &n);

    printf("Enter numbers for each element:");
    for (i = 0; i < n; ++i) {
        scanf("%f", &data[i]);
    }

    printf("Result of Standard Deviation: %.10f", calculateSD(data, n));
    return 0;
}
