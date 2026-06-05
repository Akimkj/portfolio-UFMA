public class RubroNegra<AnyType> {
    private static class NoRN<AnyType> {
        AnyType elemento;
        NoRN<AnyType> pai, esquerdo, direito, irmao;
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
        x.direito = y.esquerdo;

        if (y.esquerdo != this.Nil) {
            y.esquerdo.pai = x;
            y.esquerdo.irmao = x.esquerdo;
        }

        if (x.esquerdo != this.Nil) {
            x.esquerdo.irmao = y.direito;
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

        x.irmao = y.direito;
        if (y.direito != this.Nil) {
            y.direito.irmao = x;
        }
    }

    private void RIGHT_ROTATE(NoRN<AnyType> x) {
        NoRN<AnyType> y = x.esquerdo;
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
                if (y.cor == RubroNegra.RED) {
                    z.pai.cor = RubroNegra.BLACK;
                    y.cor = RubroNegra.BLACK;
                    y.pai.cor = RubroNegra.RED;
                    z = y.pai;
                }
            } else {
                //repetir acima mas troca direita <-> esquerda
            }
        }
    }
}
