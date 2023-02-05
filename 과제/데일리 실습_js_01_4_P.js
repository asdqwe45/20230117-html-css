const p1 = ['rock', 'paper', 'scissors', 'scissors', 'rock', 'rock', 'paper', 'paper', 'rock', 'scissors']
const p2 = ['paper', 'paper', 'rock', 'scissors', 'paper', 'scissors', 'scissors', 'rock', 'rock', 'rock']

const playGame = (p1_choice, p2_choice) => {
	if(p1_choice===p2_choice)
	{
		return 0;
	}
	else if(p1_choice==='rock'&&p2_choice==='paper')
	{
		return 2;
	}
	else if(p1_choice==='rock'&&p2_choice==='scissors')
	{
		return 1;
	}
	else if(p1_choice==='scissors'&&p2_choice==='rock')
	{
		return 2;
	}
	else if(p1_choice==='scissors'&&p2_choice==='paper')
	{
		return 1;
	}
	else if(p1_choice==='paper'&&p2_choice==='scissors'){
return 2;
	}
	else if(p1_choice==='paper'&&p2_choice==='rock')
	{
		return 1;
	}
}
for(let i=0;i<p1.length;i++){
	console.log(playGame(p1[i],p2[i]));
}
// 2
// 0
// 2
// 0
// 2
// 1
// 2
// 1
// 0
// 2