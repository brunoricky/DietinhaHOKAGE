\ENCODING=ISO-8859-1
\Problem name: IloCplex

Minimize
 obj: 0.04 X(0) + 0.01 X(1) + 0.02 X(2)
Subject To
 c1: 0.1 X(0) + X(1) + 0.7 X(2) <= 250
 c2: 0.9 X(0) + 0.1 X(1) + 0.3 X(2) <= 150
 c3: 0.1 X(0) + 0.01 X(1) + 0.2 X(2) <= 60
Bounds
 0 <= X(0) <= 9.22337203685478e+18
 0 <= X(1) <= 9.22337203685478e+18
 0 <= X(2) <= 9.22337203685478e+18
Generals
 X(0)  X(1)  X(2) 
End
