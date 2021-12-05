public static List<Integer> voraz(List<Integer> c, int l,
        Predicate<? extends List<Integer>> m, Predicate<? extends Integer> f,
          Predicate<? extends Integer> r) {
  List<Integer> sol = new LinkedList<>();
  List<Integer> con = new LinkedList<>(c);
  boolean check = false;

  while(!con.isEmpty() && !check) {
    int max = m.test(con);
    if(!(f.test(max))) con.remove(max);
    else {sol.add(max); l -= max;}
    check = r.test(l);
  }

  return sol;
}
