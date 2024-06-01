#include <iostream>
#include <random>
#include <string>

// 生成随机字符串表示的数字，范围 [min, max]
std::string GenerateRandomNumberString(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    int number = dis(gen);
    return std::to_string(number);
}

// 生成 SQL 插入语句，现在接收 uid 作为参数
std::string GenerateInsertStatement(int uid) {
    std::string bedTime = GenerateRandomNumberString(0, 3);
    std::string wakeUpTime = GenerateRandomNumberString(0, 3);
    std::string sleepQuality = GenerateRandomNumberString(0, 2);
    std::string domStudy = GenerateRandomNumberString(0, 1);
    std::string smoke = GenerateRandomNumberString(0, 1);
    std::string drink = GenerateRandomNumberString(0, 1);
    std::string snore = GenerateRandomNumberString(0, 1);
    std::string chattingSharinsThoushts = GenerateRandomNumberString(0, 2);
    std::string leanliness = GenerateRandomNumberString(0, 3);
    std::string cleaningfrsgueney = GenerateRandomNumberString(0, 4);
    std::string showerFrequency = GenerateRandomNumberString(0, 3);
    std::string monthlyBudget = GenerateRandomNumberString(0, 3);
    std::string jointOutings = GenerateRandomNumberString(0, 2);
    std::string sharedExpenses = GenerateRandomNumberString(0, 2);
    std::string sharedInterests = GenerateRandomNumberString(0, 1);

    std::string sql = "INSERT INTO user_questionnaire_datas (uid, bedTime, wakeUpTime, sleepQuality, "
                      "domStudy, smoke, drink, snore, chattingSharinsThoushts, leanliness, "
                      "cleaningfrsgueney, showerkrequency, monthlyBudset, jointOutings, "
                      "sharedExpenses, sharedInterests) VALUES (" +
                      std::to_string(uid) + ", '" + bedTime + "', '" + wakeUpTime + "', '" + sleepQuality + "', '" +
                      domStudy + "', '" + smoke + "', '" + drink + "', '" + snore + "', '" +
                      chattingSharinsThoushts + "', '" + leanliness + "', '" + cleaningfrsgueney + "', '" +
                      showerFrequency + "', '" + monthlyBudget + "', '" + jointOutings + "', '" +
                      sharedExpenses + "', '" + sharedInterests + "');";
    return sql;
}

int main() {
    freopen("datasheet3.txt","w",stdout);
    for (int uid = 2; uid <= 201; uid++) {
        std::string sqlStatement = GenerateInsertStatement(uid);
        std::cout << sqlStatement << '\n';
    }
    return 0;
}
