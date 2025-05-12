

### ✅ **README.md**

````markdown
# 📊 University Rankings CSV Parser (C++)

This project demonstrates how to parse a real-world CSV dataset using C++ with exception handling. It reads the **2012 world university rankings** dataset and stores each valid line into a vector of `UniversityRanking` objects.

---

## 🔍 Features

- Parses CSV line-by-line and extracts structured data
- Implements exception handling for malformed data
- Outputs:
  - Total lines read
  - Number of valid records parsed
  - First 3 parsed entries

---

## 🧠 Technologies Used

- C++
- Standard Template Library (STL)
- File I/O and String Streams
- Exception handling

---

## 🏫 Dataset

The CSV file includes data from 2012 world university rankings and can be found in `data/university_data.csv`.

| world_rank | institution                     | country        | score | year |
|------------|----------------------------------|----------------|-------|------|
| 1          | Harvard University               | USA            | 100   | 2012 |
| 2          | MIT                              | USA            | 91.67 | 2012 |
| ...        | ...                              | ...            | ...   | ...  |

Full data: [Source: Kaggle / EU Data Portal](https://www.kaggle.com/datasets)

---

## 🛠 How to Build & Run

### Prerequisites

- C++17 compatible compiler (e.g., `g++`, `clang++`)
- Make sure the CSV file is placed in a `data/` folder at project root

### Compile

```bash
g++ src/main.cpp -o csvparser
````

### Run

```bash
./csvparser
```

### Sample Output

```
Total lines read: 2200
Valid records parsed: 2200
First 3 valid universities:
1: Harvard University (USA) - Score: 100, Year: 2012
2: MIT (USA) - Score: 91.67, Year: 2012
3: Stanford University (USA) - Score: 89.5, Year: 2012
```

---

## 🧾 License

This project is licensed under the MIT License. See `LICENSE` for details.

