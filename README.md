# CCpp2017

## 基本操作流程

1. 从 [https://github.com/luckymark/CCpp2017](https://github.com/luckymark/CCpp2017) fork 到你自己的github中
2. 创建本地仓库：(如果用机房的电脑，则建议clone到U盘，便于携带)

	```
	git clone https://github.com/ **YourGithubAccount** /CCpp2017
	cd CCpp2017
	ls
	
	git config user.name=???
	git config user.email=??? 
	
	git remote -v
	git remote add upstream https://github.com/luckymark/CCpp2017
	```
	
3. 修改、提交代码：

	```
	git status
	git add .
	git commit -m "完成了running letter"
	git push
	```	

4. 从 https://github.com/luckymark/CCpp2017 获取更新

	```
	git fetch upstream
	git merge upstream/master
	```	
	[在github网页上更新的方法](https://www.zhihu.com/question/20393785/answer/30725725)
	
	[fork后如何同步源的新更新](https://segmentfault.com/q/1010000002590371)
	
5. 请求老师review代码的方法：在github网页上发起一个PR（pull request）即可

## [作业](https://github.com/luckymark/CCpp2017/tree/master/practices)

1. level0 可选，用于还不够熟练的同学练手（嫌题目太少的同学，那就刷刷咱[神技大学的OJ](http://acm.uestc.edu.cn/#/)吧，从低到高地刷哈）
2. level1 必做，课堂＋课后练习
3. level2 可选，供精力旺盛到变态的大神们发泄之用

## 参考

### GIT

[史上最浅显易懂的Git教程！ 廖雪峰](http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000)

[Pro Git（中文版）](http://git.oschina.net/progit/)

[撸袖子 动手学Git 专治菜鸟](http://igit.linuxtoy.org/contents.html)

[Git远程操作详解 阮一峰](http://www.ruanyifeng.com/blog/2014/06/git_remote.html)

[fork后如何跟上源repo的变化](https://segmentfault.com/q/1010000002590371)

### Markdown

[Markdown入门指南](http://www.jianshu.com/p/1e402922ee32)

### 其他

[免费的计算机编程类中文书籍](https://github.com/wwj718/free-programming-books-zh_CN)
