public class TabelaHash<E> {
    private static class Node<E> {
        private final E data;
        private final int key;
        private boolean deleted;

        Node(int key, E data) {
            this.key = key;
            this.data = data;
            this.deleted = false;
        }
    }

    private final Object[] tabHash;
    private int qtd;

    public TabelaHash(int size) {
        this.qtd = 0;
        this.tabHash = new Object[size];
    }

    private int hash(int key) {
        if (key < 0) {
            key *= -1;
        }
        return key % tabHash.length;
    }

    /**
    * Insere um novo elemento na tabela.
     @param key Identificador numérico único.
    * @param elem O objeto de tipo E a ser armazenado.
    * @return true para sucesso, false para tabela cheia.
    */
    public boolean add(int key, E elem) {
        if (this.qtd == tabHash.length) {
            return false;
        }

        int h = hash(key);

        for (int i = 0; i < tabHash.length; i++) {
            int pos = (i + h) % tabHash.length;

            Node<E> current = (Node<E>) tabHash[pos];

            if (current == null || current.deleted == true) {
                tabHash[pos] = new Node<>(key, elem);
                this.qtd++;
                return true;
            }
        }

        return false;
    }

    public int query(int key) {
        int h = hash(key);

        for (int i = 0; i < tabHash.length; i++) {
            int pos = (i + h) % tabHash.length;

            Node<E> current = (Node<E>) tabHash[pos];

            if (current == null) {
                return -1;
            }

            if (current.deleted == false && current.key == key) {
                return pos;
            }
        }
        return -1;
    }

    public E delete(int key) {
        int pos = query(key);

        if (pos == -1) {
            return null;
        }

        Node<E> curr = (Node<E>) tabHash[pos];

        curr.deleted = true;
        this.qtd--;

        return curr.data;
    }

    /**
 * Gera uma representação visual da tabela para fins de depuração.
 * Mostra índices, chaves e o estado de cada slot.
 */
public String imprimeTab() {
    StringBuilder sb = new StringBuilder();
    sb.append("--- ESTADO DA TABELA HASH ---\n");
    sb.append("Capacidade: ").append(tabHash.length).append(" | Ocupação: ").append(qtd).append("\n");

    for (int i = 0; i < tabHash.length; i++) {
        sb.append(String.format("[%03d]: ", i)); // Formata o índice com 3 dígitos

        if (tabHash[i] == null) {
            sb.append("-- vago --");
        } else {
            @SuppressWarnings("unchecked")
            Node<E> nodo = (Node<E>) tabHash[i];
            
            if (nodo.deleted) {
                sb.append("<< removido (túmulo) >>");
            } else {
                // Aqui usamos o toString() do objeto genérico E
                sb.append("Chave: ").append(nodo.key)
                  .append(" | Dado: ").append(nodo.data);
            }
        }
        sb.append("\n");
    }
        return sb.toString();
    }
    public int size() {
        return tabHash.length;
    }

}
