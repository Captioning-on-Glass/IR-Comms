#define JUROR_A_VALUE 0
#define JUROR_B_VALUE 1
#define JUROR_C_VALUE 2
#define JURY_FOREMAN_VALUE 3
#define NO_SIGNAL 4

class JurorBuffer {
    public:
    static const size_t BUFFER_SIZE = 7;
    uint16_t buf[BUFFER_SIZE] = {NO_SIGNAL, NO_SIGNAL, NO_SIGNAL, NO_SIGNAL, NO_SIGNAL};
    size_t index = 0;

    JurorBuffer() {
    }

    void add(uint16_t value) {
        this->buf[this->index] = value;
        ++index;
    }

    void clear() {
        for (auto i = 0; i < BUFFER_SIZE; ++i) {
            this->buf[i] = NO_SIGNAL;
        }
        this->index = 0;
    }

    size_t size() {
        return this->index;
    }

    bool is_full() {
        return this->index >= BUFFER_SIZE;
    }

    uint16_t mode() {
        uint16_t freq[NO_SIGNAL+1] = {0, 0, 0, 0, 0}; 
        for (auto i = 0; i < BUFFER_SIZE; ++i) {
            ++freq[this->buf[i]];
        }

        size_t mode = 0;
        uint16_t count = 0;
        for (auto i = 0; i < NO_SIGNAL+1; ++i) {
            if (freq[i] > count) {
                mode = i;
                count = freq[i];
            }
        }
        return mode;
    }
};