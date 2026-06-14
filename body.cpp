#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <map>
//程序做着玩的 也不大 就不搞分离式编译了 程序不是可以用的 做个玩具
int main() {
	int shengyu = 300;
	std::cout << "欢迎来到ColourThings AI对话框"<<std::endl;
	std::cout << "正在检测CTS AI服务"<<std::endl;
	int second = 1;
	while (second != 41) {
		++second;
		Sleep(1);
		std::cout << "\r正在尝试连接 时间" << second;
	}
	std::cout << "\n";
	std::cout << "链接服务器: CTS OFFICAL API" << "可用余额:300字 明天0:00重置" << std::endl;
	std::map<std::string, std::string> answer = { {"你是谁","我是CTS AI助手。可别问我问题烦我哦！"},{"你好","我不好，快点说正事。"},{"Hello","It's bad!"} };
	int line = 5;
	std::cout << "All done!" << "用时:" << second << "s" << std::endl;
	std::cout << "请在下方输入你要输入的内容" << std::endl;
	try {
		while (true) {
			std::cout << "请输入:";
			std::string cache = "";
			std::getline(std::cin, cache);
			std::cout << "\n";
			std::string cache2;
			if (shengyu >= 0) {
				if (!(cache.empty())) {
					if (answer.find(cache) != answer.end()) {
						cache = answer[cache];
						for (char i : cache) {
							Sleep(3);
							cache2.push_back(i);
							std::cout << "\r" << cache2;
						}
						shengyu -= cache.size();
						std::cout << std::endl;
					}
					else {
						cache2 = "";
						std::string ybm = "服务器繁忙，请不要多次刷流量！ Cloudflare保护CTS AI正常运行\n";
						for (char j : ybm) {
							Sleep(3);
							cache2.push_back(j);
							std::cout << "\r" << cache2;
						}
						shengyu -= 36;
						std::cout << std::endl;
					}
					line += 3;
					if (line >= 20) {
						line = 0;
						system("cls");
					}
				}
				else {
					std::cout << "要退出? 按回车后退出，否则请输入'否'。\n";
					std::getline(std::cin, cache);
					if (cache.empty()) {
						return 0;
					}
					else {
						continue;
					}
					cache = "";
				}
			}
			else {
				std::string cache4 = "";
				std::string cache3 = "剩余余额不足啊!";
				for (char ij : cache3) {
					Sleep(2);
					cache4.push_back(ij);
					std::cout << "\r" << cache4;
				}
				std::cout << std::endl;
			}
			cache = "";
			cache2 = "";
		}
	}
	catch (...) {
		std::cerr << "Emmm 错误了 但是我不想告诉你哪里错了！";
	}
	return 0;
}
