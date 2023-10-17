#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

// 트리 노드 구조체 정의
typedef struct TreeNode
{
    int weight;
    char ch;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 요소 구조체 정의
typedef struct
{
    TreeNode* ptree;
    char ch;
    int key;
} element;

// 히프 구조체 정의
typedef struct
{
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// 생성 함수
HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h)
{
    h->heap_size = 0;
}

// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_min_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);
    // 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1) && (item.key < h->heap[i / 2].key))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item; // 새로운 노드를 삽입
}

// 삭제 함수
element delete_min_heap(HeapType* h)
{
    int parent, child;
    element item, temp;
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while (child <= h->heap_size) 
    {
        // 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
        if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
        {
            child++;
        }

        if (temp.key < h->heap[child].key)
        {
            break;
        }

        // 한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;
    return item;
}

//히프 출력
void print_heap(HeapType* h)
{
    int i;
    int level = 1;

    for (i = 1; i <= h->heap_size; i++)
    {
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

//히프 정렬 
void heap_sort(int arr[], int n)
{
    HeapType* heap = create();
    init(heap);

    for (int i = 0; i < n; i++)
    {
        element item{};
        item.key = arr[i];
        insert_min_heap(heap, item);
        print_heap(heap);
    }

    for (int i = 0; i < n; i++)
    {
        element item = delete_min_heap(heap);
        arr[i] = item.key;
        print_heap(heap);
    }

    free(heap);
}

int main()
{
    int arr[] = { 34, 12, 76, 59, 32, 55, 88, 26, 16, 79, 34, 85, 29, 78, 41, 56, 86 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("<정렬>\n");
    heap_sort(arr, n);

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}