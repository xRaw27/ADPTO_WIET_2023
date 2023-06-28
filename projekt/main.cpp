#include <iostream>

#define MAX_N 20
#define MAX_M 20

#define arr(r, c) (arr[(r + 1) * MAX_M + (c + 1)])
#define horizontal(r, c) (horizontal[(r + 1) * MAX_M + (c + 1)])
#define vertical(r, c) (vertical[(r + 1) * MAX_M + (c + 1)])
#define corners(r, c) (corners[(r + 1) * MAX_M + (c + 1)])
#define T(a, r, c) (a[(r + 1) * MAX_M + (c + 1)])
#define left(x, y) (horizontal(x, y - 1))
#define right(x, y) (horizontal(x, y))
#define up(x, y) (vertical(x - 1, y))
#define down(x, y) (vertical(x, y))


int n, m;
char x;

int arr[MAX_N * MAX_M] = {0};
int horizontal[MAX_N * MAX_M] = {0};
int vertical[MAX_N * MAX_M] = {0};
int corners[MAX_N * MAX_M] = {0};


void print_result_recursion(int x, int y, int i) {
    if (corners(x, y + 1) == i + 1) {
        std::cout << "R";
        return print_result_recursion(x, y + 1, i + 1);
    }
    if (corners(x, y - 1) == i + 1) {
        std::cout << "L";
        return print_result_recursion(x, y - 1, i + 1);
    }
    if (corners(x + 1, y) == i + 1) {
        std::cout << "D";
        return print_result_recursion(x + 1, y, i + 1);
    }
    if (corners(x - 1, y) == i + 1) {
        std::cout << "U";
        return print_result_recursion(x - 1, y, i + 1);
    }
}

void print_result(int x, int y, int last) {
    std::cout << y << " " << x << std::endl;
    print_result_recursion(x, y, 1);

    if (corners(x, y + 1) == last) {
        std::cout << "L";
        return;
    }
    if (corners(x, y - 1) == last) {
        std::cout << "R";
        return;
    }
    if (corners(x + 1, y) == last) {
        std::cout << "U";
        return;
    }
    if (corners(x - 1, y) == last) {
        std::cout << "D";
        return;
    }
}


void go_left(int x, int y, int t) {
    horizontal(x, y - 1) = -t + 1;
    arr(x - 1, y - 1) += t;
    arr(x, y - 1) += t;
}

void go_right(int x, int y, int t) {
    horizontal(x, y) = -t + 1;
    arr(x - 1, y) += t;
    arr(x, y) += t;
}

void go_up(int x, int y, int t) {
    vertical(x - 1, y) = -t + 1;
    arr(x - 1, y - 1) += t;
    arr(x - 1, y) += t;
}

void go_down(int x, int y, int t) {
    vertical(x, y) = -t + 1;
    arr(x, y - 1) += t;
    arr(x, y) += t;
}

bool check() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr(i, j) != 0) {
                return false;
            }
        }
    }
    return true;
}

void recursion(int x, int y, int i) {
    if (corners(x, y) == 1 && check()) {
        print_result(x, y, i - 1);
        std::exit(0);
    }

    if (x == 0) {
        if (y == 0) {
            corners(x, y) = i;
            if (right(x, y) == 0 && arr(x, y) != 0) {
                go_right(x, y, -1);
                recursion(x, y + 1, i + 1);
                go_right(x, y, 1);
            }
            if (down(x, y) == 0 && arr(x, y) != 0) {
                go_down(x, y, -1);
                recursion(x + 1, y, i + 1);
                go_down(x, y, 1);
            }
        } else if (y == m) {
            corners(x, y) = i;
            if (down(x, y) == 0 && arr(x, y - 1) != 0) {
                go_down(x, y, -1);
                recursion(x + 1, y, i + 1);
                go_down(x, y, 1);
            }
            if (left(x, y) == 0 && arr(x, y - 1) != 0) {
                go_left(x, y, -1);
                recursion(x, y - 1, i + 1);
                go_left(x, y, 1);
            }
        } else {
            if (left(x, y) + right(x, y) + down(x, y) > 2) {
                return;
            }
            corners(x, y) = i;
            if (right(x, y) == 0 && arr(x, y) != 0) {
                go_right(x, y, -1);
                recursion(x, y + 1, i + 1);
                go_right(x, y, 1);
            }
            if (down(x, y) == 0 && arr(x, y - 1) != 0 && arr(x, y) != 0) {
                go_down(x, y, -1);
                recursion(x + 1, y, i + 1);
                go_down(x, y, 1);
            }
            if (left(x, y) == 0 && arr(x, y - 1) != 0) {
                go_left(x, y, -1);
                recursion(x, y - 1, i + 1);
                go_left(x, y, 1);
            }
        }
    } else if (x == n) {
        if (y == 0) {
            corners(x, y) = i;
            if (up(x, y) == 0 && arr(x - 1, y) != 0) {
                go_up(x, y, -1);
                recursion(x - 1, y, i + 1);
                go_up(x, y, 1);
            }
            if (right(x, y) == 0 && arr(x - 1, y) != 0) {
                go_right(x, y, -1);
                recursion(x, y + 1, i + 1);
                go_right(x, y, 1);
            }
        } else if (y == m) {
            corners(x, y) = i;
            if (up(x, y) == 0 && arr(x - 1, y - 1) != 0) {
                go_up(x, y, -1);
                recursion(x - 1, y, i + 1);
                go_up(x, y, 1);
            }
            if (left(x, y) == 0 && arr(x - 1, y - 1) != 0) {
                go_left(x, y, -1);
                recursion(x, y - 1, i + 1);
                go_left(x, y, 1);
            }
        } else {
            if (left(x, y) + right(x, y) + up(x, y) > 2) {
                return;
            }
            corners(x, y) = i;
            if (up(x, y) == 0 && arr(x - 1, y - 1) != 0 && arr(x - 1, y) != 0) {
                go_up(x, y, -1);
                recursion(x - 1, y, i + 1);
                go_up(x, y, 1);
            }
            if (right(x, y) == 0 && arr(x - 1, y) != 0) {
                go_right(x, y, -1);
                recursion(x, y + 1, i + 1);
                go_right(x, y, 1);
            }
            if (left(x, y) == 0 && arr(x - 1, y - 1) != 0) {
                go_left(x, y, -1);
                recursion(x, y - 1, i + 1);
                go_left(x, y, 1);
            }
        }
    } else {
        if (y == 0) {
            if (right(x, y) + up(x, y) + down(x, y) > 2) {
                return;
            }
            corners(x, y) = i;
            if (up(x, y) == 0 && arr(x - 1, y) != 0) {
                go_up(x, y, -1);
                recursion(x - 1, y, i + 1);
                go_up(x, y, 1);
            }
            if (right(x, y) == 0 && arr(x - 1, y) != 0 && arr(x, y) != 0) {
                go_right(x, y, -1);
                recursion(x, y + 1, i + 1);
                go_right(x, y, 1);
            }
            if (down(x, y) == 0 && arr(x, y) != 0) {
                go_down(x, y, -1);
                recursion(x + 1, y, i + 1);
                go_down(x, y, 1);
            }
        } else if (y == m) {
            if (left(x, y) + up(x, y) + down(x, y) > 2) {
                return;
            }
            corners(x, y) = i;
            if (up(x, y) == 0 && arr(x - 1, y - 1) != 0) {
                go_up(x, y, -1);
                recursion(x - 1, y, i + 1);
                go_up(x, y, 1);
            }
            if (down(x, y) == 0 && arr(x, y - 1) != 0) {
                go_down(x, y, -1);
                recursion(x + 1, y, i + 1);
                go_down(x, y, 1);
            }
            if (left(x, y) == 0 && arr(x - 1, y - 1) != 0 && arr(x, y - 1) != 0) {
                go_left(x, y, -1);
                recursion(x, y - 1, i + 1);
                go_left(x, y, 1);
            }
        } else {
            if (left(x, y) + right(x, y) + up(x, y) + down(x, y) > 2) {
                return;
            }
            corners(x, y) = i;

            // arr(x - 1, y - 1)  arr(x - 1, y)
            // arr(x, y - 1)      arr(x, y)
            if (up(x, y) == 0 && arr(x - 1, y - 1) != 0 && arr(x - 1, y) != 0) {
                go_up(x, y, -1);
                recursion(x - 1, y, i + 1);
                go_up(x, y, 1);
            }
            if (right(x, y) == 0 && arr(x - 1, y) != 0 && arr(x, y) != 0) {
                go_right(x, y, -1);
                recursion(x, y + 1, i + 1);
                go_right(x, y, 1);
            }
            if (down(x, y) == 0 && arr(x, y - 1) != 0 && arr(x, y) != 0) {
                go_down(x, y, -1);
                recursion(x + 1, y, i + 1);
                go_down(x, y, 1);
            }
            if (left(x, y) == 0 && arr(x - 1, y - 1) != 0 && arr(x, y - 1) != 0) {
                go_left(x, y, -1);
                recursion(x, y - 1, i + 1);
                go_left(x, y, 1);
            }
        }
    }
    corners(x, y) = 0;
}

void start_horizontal(int x, int y) {
    horizontal(x, y) = 2;
    corners(x, y) = 1;
    arr(x - 1, y) -= 1;
    arr(x, y) -= 1;
    recursion(x, y + 1, 2);
    horizontal(x, y) = 0;
    corners(x, y) = 0;
    arr(x - 1, y) += 1;
    arr(x, y) += 1;
}

void start_vertical(int x, int y) {
    vertical(x, y) = 2;
    corners(x + 1, y) = 1;
    arr(x, y - 1) -= 1;
    arr(x, y) -= 1;
    recursion(x, y, 2);
    vertical(x, y) = 0;
    corners(x + 1, y) = 0;
    arr(x, y - 1) += 1;
    arr(x, y) += 1;
}

void start() {
    // 2 in a row
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            if (arr(i, j) == 3 && (arr(i, j + 1) == 0 || arr(i, j + 1) == 2 || arr(i, j + 1) == 3)) {
                start_vertical(i, j);
            }
        }
        if (arr(i, m - 1) == 3 && (arr(i, m - 2) == 0 || arr(i, m - 2) == 2 || arr(i, m - 2) == 3)) {
            start_vertical(i, m);
        }
    }

    // 2 in a col
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr(i, j) == 3 && (arr(i + 1, j) == 0 || arr(i + 1, j) == 2 || arr(i + 1, j) == 3)) {
                start_horizontal(i, j);
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        if (arr(n - 1, j) == 3 && (arr(n - 2, j) == 0 || arr(n - 2, j) == 2 || arr(n - 2, j) == 3)) {
            start_horizontal(n, j);
        }
    }

    // find any 3
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr(i, j) == 3) {
                start_horizontal(i, j);
                start_horizontal(i + 1, j);
                start_vertical(i, j);
                start_vertical(i, j + 1);
            }
        }
    }

    // find any 2
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr(i, j) == 2) {
                start_horizontal(i, j);
                start_horizontal(i + 1, j);
                start_vertical(i, j);
                start_vertical(i, j + 1);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> m;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> x;
            arr(i, j) = x - 48;
        }
    }

    start();

    return 0;
}
