public class RubroNegra<AnyType> {
    private static class NoRN<AnyType> {
        AnyType elemento;
        NoRN<AnyType> pai, esquerdo, direito, irmao; //Referência explicita do irmao
        boolean cor;
        int codigo;

        NoRN(int codigo, AnyType e) {
            this(codigo ,e, null, null, null, null);
        }

        NoRN(int codigo, AnyType e, NoRN<AnyType> pai, NoRN<AnyType> irmao, NoRN<AnyType> esq, NoRN<AnyType> dir) {
            this.codigo = codigo;
            this.elemento = e;
            this.esquerdo = esq;
            this.direito = dir;
            this.pai = pai;
            this.irmao = irmao;
            this.cor = RubroNegra.RED;
        }
    }

    private static final boolean RED = false;
    private static final boolean BLACK = true;

    private NoRN<AnyType> root;
    private NoRN<AnyType> Nil;

    public RubroNegra() {
       this.Nil = new NoRN<>(-1,null);
       this.Nil.cor = RubroNegra.BLACK;
       this.root = this.Nil;
    }

    

    private void LEFT_ROTATE(NoRN<AnyType> x) {
        NoRN<AnyType> y = x.direito;
        NoRN<AnyType> z = x.irmao; //Salva irmao de x
        x.direito = y.esquerdo;

        //atribuição dos novos irmaos dos filhos de x
        if (y.esquerdo != this.Nil) {
            y.esquerdo.pai = x;
            y.esquerdo.irmao = x.esquerdo;
        }

        if (x.esquerdo != this.Nil) {
            x.esquerdo.irmao = x.direito;
        }

        y.pai = x.pai;
        if (x.pai == this.Nil) {
            this.root = y;
        } else if (x == x.pai.esquerdo) {
            x.pai.esquerdo = y;
        } else {
            x.pai.direito = y;
        }

        y.esquerdo = x;
        x.pai = y;

        //atualizacao dos irmãos dos nós filhos de y
        x.irmao = y.direito;
        if (y.direito != this.Nil) {
            y.direito.irmao = x;
        }

        //atualização do irmao de y
        y.irmao = z;
        if (z != this.Nil) {
            z.irmao = y;
        }
    }

    private void RIGHT_ROTATE(NoRN<AnyType> x) {
        NoRN<AnyType> y = x.esquerdo;
        NoRN<AnyType> z = x.irmao;
        x.esquerdo = y.direito;
        
        if (y.direito != this.Nil) {
            y.direito.pai = x;
            y.direito.irmao = x.direito;
        }

        if (x.direito != this.Nil) {
            x.direito.irmao = x.esquerdo;
        }

        y.pai = x.pai;
        if (x.pai == this.Nil) {
            this.root = y;
        } else if (x == x.pai.direito) {
            x.pai.direito = y;
        } else {
            x.pai.esquerdo = y;
        }

        y.direito = x;
        x.pai = y;

        x.irmao = y.esquerdo;
        if (y.esquerdo != this.Nil) {
            y.esquerdo.irmao = x;
        }

        y.irmao = z;
        if (z != this.Nil) {
            z.irmao = y;
        }
    }

    public boolean insert(int codigo, AnyType e) {
        NoRN<AnyType> newnode = new NoRN<>(codigo, e);

        return RB_INSERT(newnode);
    }

    private boolean RB_INSERT(NoRN<AnyType> z) {
        NoRN<AnyType> y = this.Nil;
        NoRN<AnyType> x = this.root; //um espectador
        while (x != this.Nil) { 
            y = x;
            if (z.codigo == x.codigo) {
                return false;
            } else if (z.codigo < x.codigo) {
                x = x.esquerdo;
            } else {
                x = x.direito;
            }
        }

        z.pai = y;
        if (y == this.Nil) {
            this.root = z;
            z.irmao = this.Nil;
        } else if (z.codigo < y.codigo) {
            y.esquerdo = z;
            z.irmao = y.direito;
            if (y.direito != this.Nil) {
                y.direito.irmao = z;
            }
        } else {
            y.direito = z;
            z.irmao = y.esquerdo;
            if (y.esquerdo != this.Nil) {
                y.esquerdo.irmao = z;
            }
        }
        z.direito = this.Nil;
        z.esquerdo = this.Nil;
        z.cor = RubroNegra.RED;
        RB_INSERT_FIXUP(z);
        return true;
    }

    private void RB_INSERT_FIXUP(NoRN<AnyType> z) {
        while (z.pai.cor == RubroNegra.RED) {
            if (z.pai == z.pai.pai.esquerdo) {
                NoRN<AnyType> y = z.pai.irmao;
                if (y.cor == RubroNegra.RED) { //caso 1
                    z.pai.cor = RubroNegra.BLACK;
                    y.cor = RubroNegra.BLACK;
                    z.pai.pai.cor = RubroNegra.RED;
                    z = z.pai.pai;
                } else {
                    if (z == z.pai.direito) { //caso 2
                        z = z.pai;
                        LEFT_ROTATE(z);
                    }
                    //caso 3
                    z.pai.cor = RubroNegra.BLACK;
                    z.pai.pai.cor = RubroNegra.RED;
                    RIGHT_ROTATE(z.pai.pai);
                }
            } else {
                NoRN<AnyType> y = z.pai.irmao;
                if (y.cor == RubroNegra.RED) { //caso 1
                    z.pai.cor = RubroNegra.BLACK;
                    y.cor = RubroNegra.BLACK;
                    y.pai.cor = RubroNegra.RED;
                    z = y.pai;
                } else {
                    if (z == z.pai.esquerdo) { //caso 2
                        z = z.pai;
                        RIGHT_ROTATE(z);
                    }
                    //caso 3
                    z.pai.cor = RubroNegra.BLACK;
                    z.pai.pai.cor = RubroNegra.RED;
                    LEFT_ROTATE(z.pai.pai);
                }
            }
        }
        this.root.cor = RubroNegra.BLACK;
    }

    public AnyType remove(int codigo) {
        NoRN<AnyType> spec = RB_SEARCH(codigo);
        if (spec != this.Nil) {
            return RB_DELETE(spec);
        }
        return this.Nil.elemento;
    }

    private AnyType RB_DELETE(NoRN<AnyType> z) {
        NoRN<AnyType> y, x;
        if (z.esquerdo == this.Nil || z.direito == this.Nil) {
            y = z;
        } else {
            y = TREE_SUCESSOR(z);
        }

        if (y.esquerdo != this.Nil) {
            x = y.esquerdo;
        } else {
            x = y.direito;
        }
        x.pai = y.pai;
        if (y.pai == this.Nil) {
            this.root = x;
        } else if (y == y.pai.esquerdo) {
            y.pai.esquerdo = x;
            x.irmao = y.irmao;
            if (x.irmao != this.Nil) {
                x.irmao.irmao = x;
            }
        } else {
            y.pai.direito = x;
            x.irmao = y.irmao;
            if (x.irmao != this.Nil) {
                x.irmao.irmao = x;
            }
        }

        if (y != z) {
            z.codigo = y.codigo;
            z.elemento = y.elemento;
        }
        if (y.cor == RubroNegra.BLACK) {
            RB_DELETE_FIXUP(x);
        }
        return y.elemento;
    }

    private void RB_DELETE_FIXUP(NoRN<AnyType> x) {
        while (x != this.root && x.cor == RubroNegra.BLACK) {
            if (x == x.pai.esquerdo) {
                NoRN<AnyType> w = x.irmao;
                if (w.cor == RubroNegra.RED) {
                    w.cor = RubroNegra.BLACK;
                    x.pai.cor = RubroNegra.RED;
                    LEFT_ROTATE(x.pai);
                    w = x.irmao;
                }
                if (w.esquerdo.cor == RubroNegra.BLACK && w.direito.cor == RubroNegra.BLACK) {
                    w.cor = RubroNegra.RED;
                    x = x.pai;
                } else {
                    if (w.direito.cor == RubroNegra.BLACK) {
                        w.esquerdo.cor = RubroNegra.BLACK;
                        w.cor = RubroNegra.RED;
                        RIGHT_ROTATE(w);
                        w = x.irmao;
                    } 
                    w.cor = x.pai.cor;
                    x.pai.cor = RubroNegra.BLACK;
                    w.direito.cor = RubroNegra.BLACK;
                    LEFT_ROTATE(x.pai);
                    x = this.root;
                }
            } else {
                NoRN<AnyType> w = x.irmao;
                if (w.cor == RubroNegra.RED) {
                    w.cor = RubroNegra.BLACK;
                    x.pai.cor = RubroNegra.RED;
                    RIGHT_ROTATE(x.pai);
                    w = x.irmao;
                }
                if (w.direito.cor == RubroNegra.BLACK && w.esquerdo.cor == RubroNegra.BLACK) {
                    w.cor = RubroNegra.RED;
                    x = x.pai;
                } else {
                    if (w.esquerdo.cor == RubroNegra.BLACK) {
                        w.direito.cor = RubroNegra.BLACK;
                        w.cor = RubroNegra.RED;
                        LEFT_ROTATE(w);
                        w = x.irmao;
                    } 
                    w.cor = x.pai.cor;
                    x.pai.cor = RubroNegra.BLACK;
                    w.esquerdo.cor = RubroNegra.BLACK;
                    RIGHT_ROTATE(x.pai);
                    x = this.root;
                }
            }
        }
        x.cor = RubroNegra.BLACK;
    }

    private NoRN<AnyType> TREE_SUCESSOR(NoRN<AnyType> z) {
        z = z.direito;
        while (z.esquerdo != this.Nil) {
            z = z.esquerdo;
        }
        return z;
    }

    public AnyType search(int codigo) {
        return RB_SEARCH(codigo).elemento;
    }

    private NoRN<AnyType> RB_SEARCH(int codigo) {
        NoRN<AnyType> x = this.root;
        while (x != this.Nil) { 
            if (codigo == x.codigo) {
                return x;
            } else if (codigo < x.codigo) {
                x = x.esquerdo;
            } else {
                x = x.direito;
            }
        }
        return this.Nil;
    }

    /*Funções auxiliares apenas para ajudar na visualizacao da árvore*/
    public void printAll(int type) {
        if (type == 1) {
            preOrder(this.root);
        } else if (type == 2) {
            inOrder(this.root);
        } else {
            posOrder(this.root);
        }
        
    }

    private void preOrder(NoRN<AnyType> x) {
        if (x != this.Nil) {
            String cor;
            if (x.cor == RubroNegra.BLACK) {
                cor = "black";
            } else {
                cor = "red";
            }
            System.out.println(x.codigo + " | " + cor + " -> " + x.elemento.toString());
            preOrder(x.esquerdo);
            preOrder(x.direito);
        }
    }

    private void inOrder(NoRN<AnyType> x) {
        if (x != this.Nil) {
            inOrder(x.esquerdo);
            String cor;
            if (x.cor == RubroNegra.BLACK) {
                cor = "black";
            } else {
                cor = "red";
            }
            System.out.println(x.codigo + " | " + cor + " -> " + x.elemento.toString());
            inOrder(x.direito);
        }
    }

    private void posOrder(NoRN<AnyType> x) {
        if (x != this.Nil) {
            posOrder(x.esquerdo);
            posOrder(x.direito);
            String cor;
            if (x.cor == RubroNegra.BLACK) {
                cor = "black";
            } else {
                cor = "red";
            }
            System.out.println(x.codigo + " | " + cor + " -> " + x.elemento.toString());
        }
    }
}   
