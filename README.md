# 🟣 CRSP – Cycle RSP

> 🕹️ A Cycle-Accurate Reality Signal Processor (RSP) plugin for the Nintendo 64, targeting perfection in every N64 game, ROM hack, mod and homebrew.  
> Built from scratch for extreme accuracy — not just compatibility. This is **CYCLE RSP**, reborn.

---

## 💡 What is CRSP?

CRSP (Cycle RSP) is a **low-level (LLE)** software renderer and plugin that simulates the Nintendo 64's RSP **cycle by cycle**, **instruction by instruction**, with a focus on total accuracy and long-term maintainability.

🔧 Built in C++  
⚙️ Precision tested  
📚 Based on official and reverse-engineered SGI/Nintendo specs

---

## 🚀 Goals

- ✅ Support all N64 games, ROM hacks, mods and homebrew titles
- ✅ Instruction timing accuracy
- ✅ Accurate behavior in all edge cases (e.g., undefined opcodes, pipeline stalls)
- ✅ Modular design to replace or extend existing emulator RSP plugins
- ✅ Long-term commitment: developed with care by a young, passionate engineer

---

## 🔧 Build & Install

See [CRSP_build_instructions.txt](CRSP_build_instructions.txt) for full instructions.

Supported:
- Windows (Win32 & Win64)
- Linux (x86 & x64)

```bash
# Example Linux build
mkdir build
cd build
cmake ..
make
```

---

## License

This project is licensed under the **SGI Free Software License B Version 2.0**.

You can find the full license text in the [LICENSE](LICENSE) file.
