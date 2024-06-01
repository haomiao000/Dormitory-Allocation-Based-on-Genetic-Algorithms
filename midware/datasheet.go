package midware

import "time"

// 登录表
type Login struct {
	UID          int64   `gorm:"column:uid;auto_increment;primary_key"`
	Authority    int64  `gorm:"column:authority;       type:INT"`
	SchoolNumber string `gorm:"column:schoolNumber;    type:NVARCHAR NOT NULL"`
	PassWord     string `gorm:"column:passWord;        type:NVARCHAR NOT NULL"`
}

type UserBaseInfo struct {
	UID                    int64  `gorm:"column:uid;							type:INT"`		//唯一（可以生成自增）				
	Name                   string `gorm:"column:name;						type:NVARCHAR"` //(随机字符串汉字 or 5位英文名都行)
	Sex                    string `gorm:"column:sex;						type:NVARCHAR"`	//0 or 1
	Major                  string `gorm:"column:major;						type:NVARCHAR"` //随机字符串
	Age                    string `gorm:"column:age;							type:NVARCHAR"` // 数字年龄
	Homestr                string `gorm:"column:home;						type:NVARCHAR"` //"天津市,河东区"
	SychronizedSchedule    string `gorm:"column:sychronizedSchedule;			type:NVARCHAR"` //"0"
	SpendingResponsibility string `gorm:"column:spendingResponsibility;		type:NVARCHAR"` //"娱乐活动"
	Interests              string `gorm:"column:interests;					type:NVARCHAR"` //"读书学习"
	Ethnic 	 			   string `gorm:"column:ethnic;						type:NVARCHAR"`//随机字符串
	StudentId			   string `gorm:"column:studentnumber;				type:NVARCHAR"`//随机10位数字
}

type UserQuestionnaireData struct {
	UID                     int64   `gorm:"column:uid;						type:INT"` //唯一（可以生成自增）
	BedTime                 string `gorm:"column:bedTime;					type:NVARCHAR"` //0-3
	WakeUpTime              string `gorm:"column:wakeUpTime;					type:NVARCHAR"` //0-3
	SleepQuality            string `gorm:"column:sleepQuality;				type:NVARCHAR"` //0-2
	DomStudy                string `gorm:"column:domStudy;					type:NVARCHAR"` //0-1
	Smoke                   string `gorm:"column:smoke;						type:NVARCHAR"` //0-1
	Drink                   string `gorm:"column:drink;						type:NVARCHAR"` //0-1
	Snore                   string `gorm:"column:snore;						type:NVARCHAR"` //0-1
	ChattingSharinsThoushts string `gorm:"column:chattingSharinsThoushts;	type:NVARCHAR"` //0-2
	Leanliness              string `gorm:"column:leanliness;					type:NVARCHAR"` //0-3
	Cleaningfrsgueney       string `gorm:"column:cleaningfrsgueney;			type:NVARCHAR"` //0-4
	ShowerFrequency         string `gorm:"column:showerkrequency;			type:NVARCHAR"` //0-3
	MonthlyBudget           string `gorm:"column:monthlyBudset;				type:NVARCHAR"` //0-3
	JointOutings            string `gorm:"column:jointOutings;				type:NVARCHAR"` //0-2
	SharedExpenses          string `gorm:"column:sharedExpenses;				type:NVARCHAR"` //0-2
	SharedInterests         string `gorm:"column:sharedInterests;			type:NVARCHAR"` //0-1
}

// 分配结果表
type DistributionResult struct {
	AllocationID        int64  `gorm:"column:AllocationID;auto_increment;primary_key"`
	RoomNumber          string `gorm:"column:RoomNumber;          			type:NVARCHAR"`
	UID                 int64  `gorm:"column:UID;       					type:INT"`
	DecisionForReassign string `gorm:"column:DecisionForReassign;           type:NVARCHAR"`
	ReassignResult      string `gorm:"column:ReassignResult;          		type:NVARCHAR"`
}

// 信息反馈表
type InformationFeedback struct {
	FeedbackID      int64     `gorm:"column:feedbackid;auto_increment;primary_key"`
	UID             int64     `gorm:"column:uid;       						type:INT"`
	FeedbackContent string    `gorm:"column:feedbackcontent;          		type:NVARCHAR"`
	TimeStamp       time.Time `gorm:"column:timestamp;          			type:TIMESTAMP"`
}

//反馈信息表
type UserFeedback struct {
	ID              uint   `gorm:"column:id;auto_increment;primary_key"`
	UserID          int64  `gorm:"not null"`
	FeedbackContent string `gorm:"type:TEXT"`
	Timestamp       time.Time
}

func (Login) TableName() string {
	return "logins"
}

func (UserBaseInfo) TableName() string {
	return "user_base_infos"
}

func (UserQuestionnaireData) TableName() string {
	return "user_questionnaire_datas"
}

func (DistributionResult) TableName() string {
	return "distribution_results"
}

func (InformationFeedback) TableName() string {
	return "information_feedbacks"
}

func (UserFeedback) TableName() string {
	return "user_feedbacks"
}
