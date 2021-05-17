G = (V, E) : 그래프
w(a, b) : vertex a와 b사이의 가중치값
d[a] : 스타팅 포인트는 0으로 초기화
모든 vertex에 무한대 값을 입력. d[v]
그래프 G안의 모든 vertex를 집합 Q에 넣어 놓는다.
Q안의 원소가 null이 될 때 까지 반복

d[a]의 값이 Q집합 원소들 중에 작기 때문에 ( d[a] = 0 ) {a}가 선택됨.
집합 Q에서 {a}가 제거됨. Q = {b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,z}

a와 인접한 Q 집합의 원소 vertex들을 집합 Q’에 입력 Q’ = { b, c, d } b, c, d는 무한대.
출발점에서 각각의 거리를 계산하면,

d[b] <- min{ d[b], d[a] + w(a, b) }; w(a, b) = 2 -> d[b] = 2. /
d[c] <- min{ d[c], d[a] + w(a, c) }; w(a, c) = 4 -> d[c] = 4. /
d[d] <- min{ d[d], d[a] + w(a, d) }; w(a, d) = 1 -> d[d] = 1. /

현재까지 가장 가까운 vertex는 d이므로 집합 Q에서 d를 제거하고
Q = {b,c,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,z}

d[d] = 1, Q' = {f, g}
d[f] <- min{ d[f], d[d] + w(d, f) }; w(d, f) = 5 -> d[f] = 6. /
d[g] <- min{ d[g], d[d] + w(d, g) }; w(d, g) = 4 -> d[g] = 5. /

다음으로 출발점에서 가장 가까운 vertex는 b (= 2).
집합 Q에서 b를 제거.
Q = {c,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,z}

d[b] = 2, Q' = {c, e}
d[c] <- min{ d[c], d[b] + w(b, c) }; d[c] = 4. /
d[e] <- min{ d[e], d[b] + w(b, e) }; d[e] = 3. /

다음으로 가까운 e를 Q에서 제거하고
Q = {c,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,z}

d[e] = 3, Q' = {c, h}
d[c] <- min{ d[c], d[e] + w(e, c) }; (d[c] = 4) < (w(e, c) = 5) d[c] = 4. /
d[h] <- min{ d[h], d[e] + w(e, h) };                            d[h] = 6. /

다음으로 작은 c와 g를 Q에서 제거
Q = {f,h,i,j,k,l,m,n,o,p,q,r,s,t,z}


d[c] = 4. Q' = { f } (a, b, e는 Q에 존재하지 않음)
d[f] <- min{ d[f], d[c] + w(c, f) }; d[f] = 6.

d[g] = 5. Q' = { f, k }
d[f] <- min{ d[f], d[g] + w(g, f) }; (6 < 8) d[f] = 6 /
d[k] <- min{ d[k], d[g] + w(g, k) };         d[k] = 7

Q <- Q - {f}; Q = {h,i,j,k,l,m,n,o,p,q,r,s,t,z}
d[f] = 6, Q' = {h, i, j}
    d[h] = 6
    d[i] = 8
    d[j] = 10

Q <- Q - {h}; Q = {i,j,k,l,m,n,o,p,q,r,s,t,z}
d[h] = 6 Q' = {l, o}
    d[l] = 7
    d[o] = 14

Q <- Q - {k}; Q = {i,j,l,m,n,o,p,q,r,s,t,z}
d[k] = 7, Q' = {j, n, r}
    d[j] = 13
    d[n] = 11
    d[r] = 9

Q <- Q - {l}; Q = {i,j,m,n,o,p,q,r,s,t,z}
d[l] = 7, Q' = {o, m, i}
    d[o] = 13
    d[m] = 10
    d[i] = 10 -> 8

Q <- Q - {i}; Q = {j,m,n,o,p,q,r,s,t,z}
d[i] = 8, Q' = {m, j}
    d[m] = 10
    d[j] = 11

Q <- Q - {r};  Q = {j,m,n,o,p,q,s,t,z}
d[r] = 9, Q' = {n, q, t}
    d[n] = 10
    d[q] = 17
    d[t] = 14

Q <- Q - {m};  Q = {j,n,o,p,q,s,t,z}
d[m] = 10, Q' = {p, n, j, o}
    d[p] = 12
    d[n] = 15 -> 10
    d[j] = 16 -> 11
    d[o] = 14 -> 13

Q <- Q - {n};  Q = {j,o,p,q,s,t,z}
d[n] = 10, Q' = {q, j}
    d[q] = 12
    d[j] = 13

Q <- Q - {j};  Q = {o,p,q,s,t,z}
d[j] = 11, Q' = {}

Q <- Q - {p};  Q = {o,q,s,t,z}
d[p] = 12, Q' = {o, s, t, q}
    d[o] = 14 -> 13
    d[s] = 14
    d[t] = 13
    d[q] = 13 -> 12

Q <- Q - {q};  Q = {o,s,t,z}
d[q] = 12, Q' = {t}
    d[t] = 15 -> 13

Q <- Q - {o};  Q = {s,t,z}
d[o] = 13, Q' = {s}
    d[s] = 19 -> 14

Q <- Q - {t};  Q = {s,z}
d[t] = 13, Q' = {z}
    d[z] = 21

Q <- Q - {s};  Q = {z}
d[s] = 14, Q' = {z}
    d[z] = 16

Q <- Q - {z};  Q = {}
d[z] = 16, Q' = {}

Q집합의 원소가 모두 제거되었으므로 알고리즘을 종료한다.
최단거리는 

adfimpsz 또는 behlmpsz로 거리는 16이다.
