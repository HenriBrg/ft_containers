# La complexité en informatique

Les algorithmes ont une complexité de n, leur coût d'exécution est donc proportionnel au nombre de données à traiter.

- Les algorithmes de complexité 1 sont évidemment les plus intéressants, mais ils sont hélas assez rares
- Une complexité de 1 pour un algorithme signifie tout simplement que son coût d'exécution est constant
- Certains algorithmes sont en revanche nettement moins performants et ont une complexité en n², soit le carré du nombre des éléments à traiter. Cette fois, cela signifie que leur coût d'exécution a tendance à croître très rapidement lorsqu'il y a de plus en plus de données

Il existe même des algorithmes encore plus coûteux, qui utilisent des exposants bien supérieurs à 2.
Inversement, certains algorithmes extrêmement astucieux permettent de réduire les complexités n ou n² en ln(n) ou n×ln(n), ils sont donc nettement plus efficaces. La fonction ln(n) est la fonction logarithmique, qui est la fonction inverse de l'exponentielle, bien connue pour sa croissance démesurée

On peut évaluer la difficulté d'un problème à partir de la complexité du meilleur algorithme qui permet de le résoudre. Par exemple, il a été démontré que le tri d'un ensemble de n éléments ne peut pas se faire en mieux que n×ln(n) opérations
