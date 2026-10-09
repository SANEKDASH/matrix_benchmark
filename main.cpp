#include <iostream>
#include <ctime>
#include <cstdlib>

template <size_t N>
class  Matrix {
	int *elems_;

public:
        Matrix() {
		elems_ = new int[N * N];
        }

        ~Matrix() {
		delete [] elems_;
	}

        void fillWith(int val) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				elems_[i * N + j] = val;
			}
		}
	}

        void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				std::cout << elems_[i * N + j] << ", ";
			}
			std::cout << std::endl;
		}

	}

        int       *operator[](size_t i)       { return &elems_[i * N]; }
	const int *operator[](size_t i) const { return &elems_[i * N]; }
};


template <int N>
void naiveMultiply(const Matrix<N> &lhs, const Matrix<N> &rhs, Matrix<N> &dst) {
        for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dst[i][j] = 0;
                        for (int k = 0; k < N; k++) {
			        dst[i][j] += lhs[i][k] * rhs[k][j];
			}
		}
	}
}

int main() {
	Matrix<8> a;
        Matrix<8> b;
	Matrix<8> c;

        a.fillWith(1);
	b.fillWith(2);

	naiveMultiply<8>(a, b, c);

	return 0;
}
