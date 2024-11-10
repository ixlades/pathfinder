int mx_sqrt(int x) {
    if (x <= 0) {
        return 0;
    }
    double temp, sqrt;

    sqrt = x / 2;
    temp = 0;
    while (sqrt != temp) {
        temp = sqrt;
        sqrt = (x / temp + temp) / 2;
    }
    int exam = sqrt;

    if (exam == sqrt) {
        return sqrt;
    }
    return 0;
}

