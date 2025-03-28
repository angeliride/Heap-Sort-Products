#include <iostream>
#include <algorithm>
#include <cstring>

struct Product {
    int price;
    int tax;

    Product(int p = 0, int t = 0) : price(p), tax(t) {}
};

class Heap {
private:
    Product* products;
    int capacity;
    int size;

    void siftUp(int index) {
        while (index > 0 && products[index].price > products[(index - 1) / 2].price) {
            std::swap(products[index], products[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void siftDown(int index) {
        while (2 * index + 1 < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && products[left].price > products[largest].price) {
                largest = left;
            }
            if (right < size && products[right].price > products[largest].price) {
                largest = right;
            }
            if (largest == index) break;

            std::swap(products[index], products[largest]);
            index = largest;
        }
    }

public:
    Heap(int maxCapacity) : capacity(maxCapacity), size(0) {
        products = new Product[capacity];
    }

    ~Heap() {
        delete[] products;
    }

    void insert(const Product& product) {
        if (size >= capacity) return;
        products[size] = product;
        siftUp(size);
        size++;

        if (products[0].price <= 0) {
            extractMax();
        }
    }

    Product extractMax() {
        if (size == 0) return Product(0, 0);

        Product maxProduct = products[0];
        products[0] = products[size - 1];
        size--;
        siftDown(0);
        return maxProduct;
    }

    void update(int a) {
        if (size == 0) return;

        Product originalProduct = products[0];
        int newPrice = originalProduct.price + a;
        extractMax();
        if (newPrice <= 0) {
            insert(originalProduct);
        } else {
            insert(Product(newPrice, originalProduct.tax));
        }
    }

    void sortHeap() {

        int index = 0;
        while (index < size) {
            if (products[index].price <= 0) {
                extractMax();
            } else {
                index++;
            }
        }
        std::sort(products, products + size, [](const Product& a, const Product& b) {
            return a.price < b.price;
        });
    }

    Product getProduct(int index) const {
        return products[index];
    }

    int getSize() const {
        return size;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;

    while (n--) {
        int o;
        std::cin >> o;

        Heap heap(o);
        int* taxes = new int[o];
        int taxCount = 0;

        while (o--) {
            char op;
            std::cin >> op;

            if (op == 'a') {
                int p, t;
                std::cin >> p >> t;
                heap.insert(Product(p, t));
                taxes[taxCount++] = t;
            } else if (op == 'p') {
                int x;
                std::cin >> x;
                heap.update(x);
            }
        }

        int size = heap.getSize();
        int validSize = 0;
        for (int i = 0; i < size; ++i) {
            if (heap.getProduct(i).price > 0) {
                validSize++;
            }
        }

        heap.sortHeap();

        int min = 0;
        std::sort(taxes, taxes + taxCount, std::greater<int>());

        for (int i = 0; i < validSize; ++i) {
            Product product = heap.getProduct(i);
            min += (product.price * taxes[i]);
        }

        std::cout << min << "\n";

        delete[] taxes;
    }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.