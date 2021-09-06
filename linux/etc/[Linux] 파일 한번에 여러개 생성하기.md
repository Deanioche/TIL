## **파일 한번에 여러개 생성하기**

___

```
touch a{001..300}.txt
```

a001.txt 부터 a300.txt 까지 생성된다.


___

## **폴더 생성하기**

```
mkdir folder{1, 2, 3} # folder1, folder2, folder3

mkdir {A..Z} # A ~ Z

mkdir test{0001..10} # test0001 ~ test0010


mkdir -p ~/rpmbuild/{BUILD,RPMS,SOURCES,SPECS,SRPMS}

[root@zetawiki ~]# ll rpmbuild
total 20
drwxr-xr-x. 2 root root 4096 Apr 29 00:33 BUILD
drwxr-xr-x. 2 root root 4096 Apr 29 00:33 RPMS
drwxr-xr-x. 2 root root 4096 Apr 29 00:33 SOURCES
drwxr-xr-x. 2 root root 4096 Apr 29 00:33 SPECS
drwxr-xr-x. 2 root root 4096 Apr 29 00:33 SRPMS
```
