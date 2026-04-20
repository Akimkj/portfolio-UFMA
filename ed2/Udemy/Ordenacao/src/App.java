import java.util.Random;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);

        System.out.print("Tamanho do vetor -> ");
        int tam = scn.nextInt();

        int[] dados = vetor(tam);

        while (true) {
            System.out.println("====================================================");
            System.out.println("         ALGORITMO DE ORDENACAO BUBBLE SORT");
            System.out.println("====================================================");
            System.out.println("0 - encerrar");
            System.out.println("1 - imprimir o vetor");
            System.out.println("2 - ordenar com Bubble");
            System.out.println("3 - ordenar com Insertion");
            System.out.println("4 - ordenar com Selection");
            System.out.println("5 - ordenar com Merge");
            System.out.println("6 - ordenar com Quick");
            System.out.println("====================================================");
            System.out.print("\nOpcao -> ");
            int opc = scn.nextInt();

            if (opc == 0) {
                break;
            } else if (opc == 1) {
                for (int i = 0; i < tam; i++) {
                    System.out.println(i + " - " + dados[i]);
                }
            } else if (opc == 2) {
                dados = bubble(dados);
            } else if (opc == 3) {
                dados = insertion(dados);
            } else if (opc == 4) {
                dados = selection(dados);
            } else if (opc == 5) {
                mergeSort(dados);
            } else if (opc == 6) {
                int high = dados.length -1;
                quickSort(dados, 0, high);
            } else if (opc == 7) {
                System.out.println("Que numero quer procurar?");
                int key = scn.nextInt();
                int res = binarySearch(dados, key);
                if (res != -1) {
                    System.out.println("ENCONTRADO! Na posição " + res);
                } else {
                    System.out.println("Elemento nao encontrado");
                }
            }

        }

        scn.close();
    }

    /*
    método para criar um vetor aleatorio de tamanho tam
     */
    private static int[] vetor(int tam) {
        Random gerador = new Random();

        int vetor[] = new int[tam];

        for (int i = 0; i < tam; i++) {
            int num = gerador.nextInt(14);
            vetor[i] = num;
        }

        return vetor;
    }

    /*Ordenação com bubble sort */
    private static int[] bubble(int[] v) {
        long inicio = System.nanoTime();

        boolean trocou = true;

        while (trocou) {
            trocou = false;
            for (int i = 0; i < v.length - 1; i++) {
                if (v[i] > v[i+1]) {
                    int aux = v[i];
                    v[i] = v[i+1];
                    v[i+1] = aux;
                    trocou = true;
                }
            }
        }

        long fim = System.nanoTime();

        System.out.println("Tempo: " + (double) ((fim - inicio) / 1000000));
        return v;
    }

    /*Insertion Sort */
    private static int[] insertion(int[] v) {
        for (int i = 1; i < v.length; i++) {
            int atual = v[i];

            for (int j = i - 1; j >= 0; j--) {
                if (atual > v[j]) {
                    break;
                } else {
                    v[j + 1] = v[j];
                    v[j] = atual;
                }
            }
        }

        return v;
    }

    private static int[] selection(int[] v) {
        int min, temp;

        for (int i = 0; i < v.length - 1; i++) {
            min = i;
            for (int j = i + 1; j < v.length; j++) {
                if (v[j] < v[min]) {
                    min = j;
                }
            }
            while (min > i && v[min-1] > v[min]) {
                temp = v[min];
                v[min] = v[min-1];
                v[min-1] = temp;
                min--;
            }
        }

        return v;
    }


    public static void mergeSort(int[] array)
	{
		if(array == null)
		{
			return;
		}

		if(array.length > 1)
		{
			int mid = array.length / 2;

			// Split left part
			int[] left = new int[mid];
			for(int i = 0; i < mid; i++)
			{
				left[i] = array[i];
			}
			
			// Split right part
			int[] right = new int[array.length - mid];
			for(int i = mid; i < array.length; i++)
			{
				right[i - mid] = array[i];
			}
			mergeSort(left);
			mergeSort(right);

			int i = 0, j = 0, k = 0;

			// Merge left and right arrays
			while(i < left.length && j < right.length)
			{
				if(left[i] < right[j])
				{
					array[k] = left[i];
					i++;
				}
				else
				{
					array[k] = right[j];
					j++;
				}
				k++;
			}
			// Collect remaining elements
			while(i < left.length)
			{
				array[k] = left[i];
				i++;
				k++;
			}
			while(j < right.length)
			{
				array[k] = right[j];
				j++;
				k++;
			}
		}
	}

    private static int partition(int[] arr, int low, int high) {
        
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high -1; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        return i +1;
    }

    public static void quickSort(int[] arr, int low, int high) {
        if (low >= high) 
            return;

        int p = partition(arr, low, high);

        quickSort(arr, low, p -1);
        quickSort(arr, p + 1, high);
    }

    public static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
}
