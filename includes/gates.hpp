#ifndef GATES
#define GATES

class gates {
 public:
  // AND gate
  bool and_gate(bool a, bool b) { return a and b; }

  // OR gate
  bool or_gate(bool a, bool b) { return a or b; }

  // NOT gate
  bool not_gate(bool a) { return !a; }

  // XOR gate
  bool xor_gate(bool a, bool b) { return a != b; }

  // NAND gate
  bool nand_gate(bool a, bool b) { return !and_gate(a, b); }

  // NOR gate
  bool nor_gate(bool a, bool b) { return !or_gate(a, b); }

  // XNOR gate
  bool xnor_gate(bool a, bool b) { return !xor_gate(a, b); }

  // Implication gate
  bool imp_gate(bool a, bool b) { return !a or b; }
};
#endif  // GATES