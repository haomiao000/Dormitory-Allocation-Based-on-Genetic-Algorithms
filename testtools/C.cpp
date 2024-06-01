#include <iostream>
#include <random>
#include <string>

// 生成随机英文名
std::string GenerateRandomName() {
    const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, chars.size() - 1);
    std::string name;
    for (int i = 0; i < 5; ++i) { // 生成 5 位英文名
        name += chars[dis(gen)];
    }
    return name;
}

// 生成随机性别 "0" 或 "1"
std::string GenerateRandomSex() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    return std::to_string(dis(gen));
}

// 生成随机专业名（随机英文字符串）
std::string GenerateRandomMajor() {
    const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, chars.size() - 1);
    std::string major;
    for (int i = 0; i < 6; ++i) { // 生成 6 位英文作为专业名
        major += chars[dis(gen)];
    }
    return major;
}

// 生成随机年龄字符串 "18" 到 "22"
std::string GenerateRandomAge() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(18, 22);
    return std::to_string(dis(gen));
}

// 生成随机民族字符串（随机长度为 3 到 6 的英文字符串）
std::string GenerateRandomEthnic() {
    const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> lengthDis(3, 6); // 随机长度为 3 到 6
    std::uniform_int_distribution<> charDis(0, chars.size() - 1);
    std::string ethnic;
    int length = lengthDis(gen); // 生成民族字符串的长度
    for (int i = 0; i < length; ++i) {
        ethnic += chars[charDis(gen)];
    }
    return ethnic;
}

// 生成随机学生编号（10位数字字符串）
std::string GenerateRandomStudentId() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long long> dis(1000000000, 9999999999);
    return std::to_string(dis(gen));
}

// 生成 SQL 插入语句，并接收uid作为参数
std::string GenerateInsertStatement(int uid) {
    std::string name = GenerateRandomName();
    std::string sex = GenerateRandomSex();
    std::string major = GenerateRandomMajor();
    std::string age = GenerateRandomAge();
    std::string ethnic = GenerateRandomEthnic();
    std::string studentId = GenerateRandomStudentId();

    std::string sql = "INSERT INTO user_base_infos (uid, name, sex, major, age, ethnic, studentnumber, home, sychronizedSchedule, spendingResponsibility, interests) VALUES (" +
                      std::to_string(uid) + ", '" + name + "', '" + sex + "', '" + major + "', '" + age +
                      "', '" + ethnic + "', '" + studentId +
                      "', '天津市,河东区', '0', '娱乐活动', '读书学习');";
    return sql;
}

int main() {
    freopen("datasheet2.txt","w",stdout);
    for (int uid = 2; uid <= 201; uid++) {
        std::string sqlStatement = GenerateInsertStatement(uid);
        std::cout << sqlStatement << std::endl;
    }
    return 0;
}
