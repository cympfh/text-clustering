# [bayon](https://code.google.com/p/bayon/wiki/Tutorial_ja) is awesome!

`bayon` を用いてテキスト(行) を bag-of-words モデルで、クラスタリングする為の周辺.

```bash
   make
g++ -O3 -std=c++11 -o tobow tobow.cc # テキストを bag-of-words (term freq) 形式にする
g++ -O3 -std=c++11 -o split split.cc # bayon の出力をテキストに戻す
```

```bash
   ./tobow < small > small.bow
   wc -l small
100 small
   bayon --idf -n 10 small.bow > small.c
   head small.c
1       39      21      79      37      25      38
2       65      63      9       64      10
3       84      75      42      86      77      41      6       80
4       43      44      46      48      40      19      62
5       26      36      78      20      35      27      33      28      61      81      85      56
6       98      97      96      99      95      60      58      94      82      24      29      59
7       54      55      32      2       16      7       18      8       17      5       31      34      83
8       52      51      53      50      90      89      88      15      87      57      76
9       73      68      66      4       92      47      22      93      49      1       23      45      3
10      72      67      69      12      13      11      14      70      71      91      74      0       30
```

```bash
   ./split -c small.c -i small
A homozygous mutation within the informative LOH was found in three of these patients.
Specific NTM pathogens were identified in six patients.
A diagnosis was established in 6% of the patients.
We identified a total of four pathogenic CNVs in three patients, and all arrays successfully detected them.
Complications such as scarring, pigmentation, and disfigurement were common in all the patients.
With the SNP arrays, we also identified a LOH containing a gene associated with a recessive disorder consistent with the patient's phenotype (i.e., an informative LOH) in four children (including two siblings).

A prolonged QTc interval was not related to serum calcium concentration and/or treatment with QTc prolongation drug, clarithromycin or azithromycin, but related to age, lower 
(cont.)
```

デフォルトで、空行がクラスタの区切り.
`-d` オプションで区切り行 (区切り文字ならぬ) を変更できる.

```bash
   ./split -c small.c -i small -d '###'
A homozygous mutation within the informative LOH was found in three of these patients.
Specific NTM pathogens were identified in six patients.
A diagnosis was established in 6% of the patients.
We identified a total of four pathogenic CNVs in three patients, and all arrays successfully detected them.
Complications such as scarring, pigmentation, and disfigurement were common in all the patients.
With the SNP arrays, we also identified a LOH containing a gene associated with a recessive disorder consistent with the patient's phenotype (i.e., an informative LOH) in four children (including two siblings).
###
A prolonged QTc interval was not related to serum calcium concentration and/or treatment with QTc prolongation drug, clarithromycin or azithromycin, but related to age, lower 
```

