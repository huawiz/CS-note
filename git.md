# Git新手教學

[Course Link](https://lidemy.com/courses/379441/lectures/5795081)

## 為什麼要用版本控制呢？
我們做報告都有經驗，同個檔案經過修改後，就會有很多種版本，而你可能會出現像是`報告1.doc`、`報告2.doc`...，如果檔案一多就很難進行管理，這時候我們就需要一個版本控制方式(軟體)，來幫助我們管理不同版本的檔案。

## 如何做版本控制？

1. 需要新版本:建立新資料夾
2. 不想加入版本控制:不要加入資料夾
3. 避免版本號衝突:用看似亂數的名字當名稱
4. 知道最新版本：使用一個檔案來存
5. 歷史紀錄：使用一個檔案來紀錄修改紀錄

## 指令

`git init` 針對專案做版本控制

`rm -r .git` 刪除.git資料夾 (刪除git功能)

`git status` check版本控制的狀態

`git add` 加入檔案進行版本控制

`git rm --cached <file>...`刪除版本控制檔案（說明文件有）

`git commit -m 'message'` 版本上傳

`git log` 版本編號

`git log --oneline` 簡化版版本編號

`git checkout` 把版本變回原本的狀態
	
	`git checkout master` 最新狀態



## .gitignore
這裡拿來存放你想忽略的檔案

## branch

![](https://i.imgur.com/ELrjiM0.png)


### 為什麽要用branch?

可以讓不同版本的程式碼，做獨立開發，最後再合併。

### branch 指令

`git branch -v` 查看branch

`git branch  branch_name` 建立新的branch

`git branch -d branch_name` 刪除branch

`git checkout branch_name` 切換branch
注意：master是一個branch

`git merge new-feature` 若在master下，把new-feature合併進來（要用git checkout master切換成master）

## 發生merger怎麼辦？

遇到conflict代表版本衝突，有可能是因為同時編輯相同的檔案。透過`git status`查看衝突檔案，然後手動修改成正確軟體，再`git commit -m'resolve commit'`，即可解決。


## Git vs GitHub
|Git|GitHub|
|---|------|
|版本控制程式|放Git repository的地方|

### 連結Github

```Shell
git remote add orgin <github_url>
git push -u orgin master
```


### Git 刪除資料夾

```Shell
git rm -r --cached FOLDER_NAME
git commit -m "YOUR_COMMENT"
git push -u origin master
```

## 狀況劇

1. 修改commit message
`git commit --amend` 修改commit message

2. 重置commit
`git reset HEAD^ --hard/--soft/--mixed`  重置commit，[補充](https://ithelp.ithome.com.tw/articles/10187303)

3. 放棄改的東西
`git checkout -- code.js` 回復到還沒改的狀態

4. 更改branch名稱
`git branch -m 123` 把branch名稱改成123

5. 把遠端的branch抓下
`git checkout branch_name` 把遠端的branch抓下來看

## 什麼是hook?

發生某事的時候通知我

可以在.git資料夾內找到hook檔案，並且在裡面的sample檔設定你要的hook。