MST-Kruskal(G, w)    		
  A = ∅
  for each vertex v ∈ G.V
    Make-Set(v)
  sort the edges of E by increasing w (weight) value
  for each edge (u, v) ∈ E (taken in weight order)
    if Find-Set(u) ≠ Find-Set(v)
     A = A ∪ {(u, v)}
     Union(u, v)
  return A