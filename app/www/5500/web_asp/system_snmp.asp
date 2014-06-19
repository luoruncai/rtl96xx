<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Pragma" content="no-cache">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title> OCN-OUTDOOR - SNMP代理设置 </title>
<script type="text/javascript" src="images/iepngfix_tilebg.js"></script> 
<style type="text/css">img, div, input { behavior: url("images/iepngfix.htc") } </style>  
<link rel="stylesheet" href="theme/cvnchina/style.css" type="text/css">
<script language=javascript src=script/env.js></script>
<script language=javascript src=script/utils.js></script>
<script language=javascript src=script/valid.js></script>
<script language=javascript src=theme/cvnchina/main.js></script>


<script language=javascript>
var env=new Array();var webVars = new Array( <% CGI_GET_WEB_CONST(); %>);

env['vendor.name'] = 'Shanghai Cloud Vision Networks Co., Ltd.';
env['vendor.link'] = 'http://www.cvnchina.com';
env['vendor.copyright'] = '2013-2020';
env['vendor.id'] = 'cvnchina';
env['vendor.logo'] = 'default';

env['sys.theme'] = 'cvnchina';
env['sys.lang'] = 'cn';
env['sys.model'] = 'OCN-OUTDOOR';
env['sys.name'] = 'EOC System';
env['sys.version'] = 'R1.0.5';
env['sys.type'] = 'eoc';
env['sys.mib'] = 'nscrtv-hc';
env['sys.ip'] = '192.168.0.100';
env['sys.user'] = 'admin';
env['sys.time'] = '946685430';
env['sys.linkup'] = '0';
env['sys.linkoff'] = '0';
env['sys.busy'] = '0';
env['sys.ipc'] = '0';
env['sys.vlan'] = '0';
env['sys.unsaved'] = webVars[1];
env['sys.feature'] = 'vlanpool;mme_drop_ports;slave_access_mgmt;bcmp;';


env['web.page'] = current_page();env['sys.parent_name'] = '';

pageRedirectCheck(env);
</script>

<script language=JavaScript>

 
var webVars = new Array( <% CGI_GET_WEB_CONST(); %>);
var syssnmp = new Array(<% CGI_SYS_SNMP_BASIC(); %>);

/*just for test
var webVars = new Array( 'EPN104', '0', '0');
var syssnmp = new Array('0;80001f88803cd4279aFFFFFFFF;1500;HanZhou China;R&D Hangzhou, Hangzhou LOSO Technologies Co., Ltd.;9;192.168.0.10;1;public;1;;0;;0;;0');//4个团体
*/

var EN_INDEX = 0;
var ID_INDEX = 1;
var PACKET_LEN_INDEX = 2;
var LOCATION_INDEX = 3;
var CONTACT_INDEX = 4;
var VERSION_INDEX = 5;
var TRUST_HOST_INDEX = 6;
var CURRENT_COUNT_INDEX = 7;
var COMM_NAME0_INDEX = 8;
var MAX_COMM_COUNT = 4;


function get_value(INDEX)
{
	if (syssnmp.length > 0)
	{
		var vs = syssnmp[0].split(';');
		if (vs.length > 0) return vs[INDEX];
	}
	return false;
}

var snmp_comm_current_count = get_value(CURRENT_COUNT_INDEX);
var snmp_comm_name = new Array(MAX_COMM_COUNT);
var snmp_comm_mode = new Array(MAX_COMM_COUNT);

var num = 0;
var index = COMM_NAME0_INDEX;
for(num=0; num< MAX_COMM_COUNT; num++)
{	
	snmp_comm_name[num] = get_value(index);
	snmp_comm_mode[num] = (parseInt(get_value(++index))==0? "只读":"读写");
	index++;
}

function choose_version(version) /*num  1:v1  3:v2 5:v3 7:all */
{	
/*
version:	v1    v2   v3    all	sum
index:		1     3    5	  7
select:		√	  √    √	        9
select:		×	  √    √	        8
select:		√	  ×    √	        6
select:		√	  √    ×	        4
select:		×	  ×    √	        5
select:		×	  √    ×	        3
select:		√	  ×    ×	        1
select:		×	  ×    ×	        0
select:			      	      √   	7
*/
	var f=document.forms[0];

	 if(1 == version)
	{
		f.VoiceMode[0].checked = true;
		f.VoiceMode[1].checked = false;
		f.VoiceMode[2].checked = false ;
	}

	else if(4 == version)
	{	
		f.VoiceMode[0].checked = false;
		f.VoiceMode[1].checked = true;
		f.VoiceMode[2].checked = false ;
	}
	else if(9 == version )
	{	
		f.VoiceMode[0].checked = false;
		f.VoiceMode[1].checked = false;
		f.VoiceMode[2].checked = true ;
	}
}

function cal_version_val()
{	
	var f=document.forms[0];	

	if(f.VoiceMode[0].checked==true)
	{
		return 1;
	}
	if(f.VoiceMode[1].checked==true)
	{
		return 4;
	}	
	if(f.VoiceMode[2].checked==true)
	{
		return 9;
	}			
}

function validValueInput(event,str1, str2, num)
{
	return true;
}

function snmp_endis()
{/*
	var f=document.forms[0];
	var dis = (f.SNMP_EN.value == 0);
	var dis2 = (f.TRAP_EN.value == 0) || dis;
	f.SNMP_RO.disabled = dis;
	f.SNMP_RW.disabled = dis;
	f.TRAP_EN.disabled = dis;
	
	for(i = 0; i < 4; i ++) { 
		f.TRAP_IP[i].disabled = dis2;
	}
	f.TRAP_CM.disabled = dis2;
*/
}

 function changeTxetState()
{
	if (!document.getElementById("SNMP_ADD_COMMUNITY").checked)
		return;
 
	if (document.getElementsByName("rb")[0].checked)
	{
		document.getElementById("txt2").disabled = true;
		document.getElementById("txt2").className = "disableElement";
		document.getElementById("slct1").disabled = false;
		document.getElementById("slct1").className = "enableElement";
	}
	else
	{
		document.getElementById("txt2").disabled = false;
		document.getElementById("txt2").className = "enableElement";
		document.getElementById("slct1").disabled = true;
		document.getElementById("slct1").className = "disableElement";
		document.getElementById("txt2").focus();
	}
}
  
function methodChange()
{
    if (document.getElementById("SNMP_ADD_COMMUNITY").checked == true)
    {
		document.getElementsByName("rb")[0].disabled = false;
		document.getElementsByName("rb")[1].disabled = false;
 
		document.getElementById("txt2").disabled = false;
		document.getElementById("slct1").disabled = false;
		document.getElementById("slct2").disabled = false;
 
		document.getElementsByName("rb")[0].checked = true;
		document.getElementById("slct1")[0].selected = true;
		document.getElementById("slct2")[0].selected = true;
 
		document.getElementById("slct2").className = "enableElement";
 
		changeTxetState();
	}
    else
    {
		document.getElementsByName("rb")[0].disabled = true;
		document.getElementsByName("rb")[1].disabled = true;
 
		document.getElementById("txt2").disabled = true;
		document.getElementById("slct1").disabled = true;
		document.getElementById("slct2").disabled = true;
 
		document.getElementById("txt2").className = "disableElement";
		document.getElementById("slct1").className = "disableElement";
		document.getElementById("slct2").className = "disableElement";
    }
}

function init()
{
	var f = document.forms[0];

	f.SNMP_EN.value = get_value(EN_INDEX);
	f.ENGINE_ID.value = get_value(ID_INDEX);
	f.SNMP_MAX_PACKET_LEN.value = get_value(PACKET_LEN_INDEX);
	f.SNMP_LOCATION.value = get_value(LOCATION_INDEX);
	f.SNMP_CONTACT.value = get_value(CONTACT_INDEX);
	choose_version(parseInt(get_value(VERSION_INDEX)));
	f.SNMP_TRUST_HOST.value = get_value(TRUST_HOST_INDEX);
	f.SNMP_ADD_COMMUNITY.checked = false;
	methodChange();
}

function find_snmp_add_comm_which_num()
{	
	var comm_index = 0;
	for(comm_index=0; comm_index < MAX_COMM_COUNT; comm_index++)
	{
		if(!snmp_comm_name[comm_index])
		{
			return comm_index
		}
	}
}

function community_do_diffCfg()
{
	 var after_add_num = 0;
	 var f=document.forms[0];

	if (document.getElementById("SNMP_ADD_COMMUNITY").checked)
	{	
		var after_add_count = ++snmp_comm_current_count;
		diffCfg("SNMP_COMM_COUNT", "snmp_comm_count", after_add_count); 
		snmp_comm_current_count--;
		
		var which_num = find_snmp_add_comm_which_num();
		diffCfg("SNMP_ADD_COMM_WHICH_NUM", "snmp_add_comm_which_num", which_num);  
		
		if (document.getElementsByName("rb")[0].checked)     
		{	
			diffCfg("SNMP_COMMUNITY_NAME_STANDARD", "snmp_add_comm_name", f.SNMP_COMMUNITY_NAME_STANDARD.value);
		}
		else
		{	
			diffCfg("SNMP_COMMUNITY_NAME_USER", "snmp_add_comm_name", f.SNMP_COMMUNITY_NAME_USER.value);
		}
		diffCfg("SNMP_ACCESS_MODE", "snmp_access_mode", f.SNMP_ACCESS_MODE.value);	
	}
}

var reg_string = /^([0-9a-zA-Z,\,,\~,\!,\@,\$,\%,\^,\&,\*,\(,\),-,\_,\+,\=,\{,\},\[,\],\:,\|,\.,\?,\<,\>]{1}[0-9a-zA-Z,\s,\,,\~,\!,\@,\$,\%,\^,\&,\*,\(,\),-,\_,\+,\=,\{,\},\[,\],\:,\|,\.,\?,\<,\>]{0,79})$/;

function CheckForm()
{
	var f=document.forms[0];
	var string = "";
	
	string = f.ENGINE_ID.value;
	reg = /^([0-9a-zA-Z]{10,31})$/;
	if(-1 == string.search(reg))
	{
		alert("引擎ID设置非法,请检查字符的长度和字符的范围(0-9,a-z,A-Z)！");
		return false;		
	}
	string = f.SNMP_MAX_PACKET_LEN.value;
	reg = /^([1-9][0-9]{3,4})$/;
	if(-1 == string.search(reg))
	{
		alert("最大包长度设置非法，请检查输入数字的长度(4-5位,以正整数开始)和范围！");
		return false;		
	}
	if((string > 64000) || (string < 1500))
	{
		alert("请输入提示范围内的整数！");
		return false;		
	}
	
	
	string = f.SNMP_LOCATION.value; 
	reg = reg_string;
	if(-1 == string.search(reg))
	{
		alert("物理位置信息不能输入非法字符:\\,\/,\",\',\;,#,空字符串,以空格开始的字符以及中文字符！");
		return false;		
	}

	string = f.SNMP_CONTACT.value;
	reg = reg_string;
	if(-1 == string.search(reg))
	{
		alert("联系信息不能输入非法字符:\\,\/,\",\',\;,#,空字符串,以空格开始的字符以及中文字符！");
		return false;		
	}


	string = f.SNMP_TRUST_HOST.value;
   	reg = /^(([1-9]|[1-9]\d|1\d\d|2[0-1]\d|22[0-3])\.){1}(([01]?\d?\d|2[0-4]\d|25[0-5])\.){2}([1-9]|[1-9]\d|1\d\d|2[0-4]\d|25[0-4])$/;
    var reg1 = /^\bdefault\b$/;
	var vs = string.split('.');
		
	if(((-1 == string.search(reg)) && (-1 == string.search(reg1))) || (127 == vs[0]))
	{
		alert("信任主机IP地址非法！");
		return false;		
	}

	if (document.getElementById("SNMP_ADD_COMMUNITY").checked)
	{	
		if(snmp_comm_current_count >= MAX_COMM_COUNT)
		{
			alert("最多只支持创建"+MAX_COMM_COUNT +"个团体！");
			return false;
		}

		if (document.getElementsByName("rb")[1].checked)  
		{
			string = f.SNMP_COMMUNITY_NAME_USER.value;
			reg = /^([0-9a-zA-Z,\,,\~,\!,\@,\$,\%,\^,\&,\*,\(,\),-,\_,\+,\=,\{,\},\[,\],\:,\|,\.,\?,\<,\>]{1,32})$/;
			if(-1 == string.search(reg))
			{
				alert("用户自定义团体名不能输入非法字符:\\,\/,\",\',\;,#,空字符串,空格以及中文字符！");
				return false;		
			}	
		}
		
		if (document.getElementsByName("rb")[0].checked)     
		{	
			string = f.SNMP_COMMUNITY_NAME_STANDARD.value;
		}
		else
		{	
			string =  f.SNMP_COMMUNITY_NAME_USER.value;
		}
		for(num=0; num< MAX_COMM_COUNT; num++)
		{	
			if(snmp_comm_name[num])
			{
				if(string == snmp_comm_name[num])
				{
					alert("团体名" +string+"已经存在!");
					return false;	
				}
			}
		}
	}

	return true;
}


function apply_all(type, comm_index)
{	
	var f=document.forms[0];
	if(0 == type)  /*确定*/
	{	
		if(false == CheckForm())
		{
				return false;
		}
		
		diffCfg("SNMP_EN", "snmp_enabled", f.SNMP_EN.value);
		diffCfg("ENGINE_ID", "snmp_engineID", f.ENGINE_ID.value);
		diffCfg("SNMP_MAX_PACKET_LEN", "snmp_max_packet_len", f.SNMP_MAX_PACKET_LEN.value);
		diffCfg("SNMP_LOCATION", "snmp_location", f.SNMP_LOCATION.value);
		diffCfg("SNMP_CONTACT", "snmp_contact", f.SNMP_CONTACT.value);
		diffCfg("SNMP_VERSION", "snmp_version",cal_version_val());
		diffCfg("SNMP_TRUST_HOST", "snmp_trust_host", f.SNMP_TRUST_HOST.value);
		if(false == community_do_diffCfg())
		{
			return false;
		}
		subForm(f,'goform/command','SNMP_BASIC', 'system_snmp.asp');
	}
	else  			/*删除*/
	{	
		diffCfg("SNMP_DEL_COMM_WHICHNUM", "snmp_del_comm_which_num", comm_index);
		subForm(f,'goform/command','SNMP_BASIC', 'system_snmp.asp');
	}	
}

</script>
</head>

<body onload=init()>
<script>pageHead(env, env['web.page']);</script>
<form name=system_snmp action=goform/command method=post onsubmit="return false;">

<table width=100% cellpadding=4 cellspacing=0>
	<tr ><td colspan=2 class="tb_head">基本设置</td> </tr>				
	<tr>
		<td class=tb_title>SNMP状态</td>
		<td class=tb_content>
			<select name=SNMP_EN onchange=snmp_endis()>
			<option value=0>关闭</option>
			<option value=1>开启</option> 
			</select>
		</td>
	</tr>
	<tr>
		<td class=tb_title>本地引擎ID</td>
			<td class=tb_content><input type="text" size="40" id="local_id" name="ENGINE_ID" maxlength="31">(10-31位数字或字母)</td>
	</tr>			

	<tr>
		<td class=tb_title>最大包长度</td>
			<td class=tb_content><input type="text" size="10" id="SNMP_MAX_PACKET_LEN" name="SNMP_MAX_PACKET_LEN" maxlength="5">(1500-64000字节)</td>
	</tr>
	<tr>
		<td class=tb_title>物理位置信息</td>
			<td class=tb_content><input type="text" size="40" id="SNMP_LOCATION" name="SNMP_LOCATION" maxlength="80">(1~80字符)</td>
	</tr>			
	<tr>
		<td class=tb_title>联系信息</td>
			<td class=tb_content><input type="text" size="40" id="SNMP_CONTACT" name="SNMP_CONTACT" maxlength="80">(1~80字符)</td>
	</tr>
	
	<tr>
		<td class=tb_title>SNMP版本</td>								
			 <td class=tb_content><input type=radio class=xuiInputRadioEnabled name="VoiceMode" id="VoiceMode" value="v1" >v1  
						  <input type=radio class=xuiInputRadioEnabled name="VoiceMode" id="VoiceMode" value="v2c" >v2c  
						  <input type=radio class=xuiInputRadioEnabled name="VoiceMode" id="VoiceMode" value="v3" >v3 
						  </td> 
	</tr>
	<tr>
		<td class=tb_title>信任的主机</td>
	        <td class=tb_content><input name="SNMP_TRUST_HOST" size=17 maxlength=15>
	<!--	<br>IP地址格式为:IP/MASK,如192.168.0.100/16,或者是"default",表示任意主机.-->
			<br>IP地址格式为点分IP地址,如192.168.0.100,或者是"default",表示任意主机.
		</td>
	</tr>
	<tr class=tb_title height=30>
			<TD class=tb_content colspan=2>&nbsp;<b>说明: </b>当设置snmp相关的配置项时，建议使snmp处于关闭状态！</TD>
		</tr>
	
	<tr>
		<td colspan=2 class="tb_head">新建团体</td>
	</tr>
	<tr class=textCell height=30>
		<td class=tb_title >新建团体</td>
		<TD class=tb_content colspan=2>&nbsp;<b><input type=checkbox name="SNMP_ADD_COMMUNITY" id="SNMP_ADD_COMMUNITY" onclick="methodChange()"> </b></TD>		
	</tr>
	 <tr>
		<td class=tb_title >团体名</td>
		 <td class=tb_content><input type =radio name="rb" id="rb" onClick="changeTxetState()">标准 <select id=slct1 name="SNMP_COMMUNITY_NAME_STANDARD" style="WIDTH: 152px"><option value="public">public</option><option value="private">private</option></select></td>			
	</tr> 
	<tr>
		<td class=tb_title >&nbsp;</td>
		<td class=tb_content><input type =radio name="rb" id="rb" onClick="changeTxetState()">用户自定义 <input type="text" size="20" id="txt2" name="SNMP_COMMUNITY_NAME_USER" id="2" maxlength="32">(1~32字符)</TD> 
			
	</tr> 
	<tr>
		<td class=tb_title>访问模式</td>
			<td class=tb_content><select id=slct2 name="SNMP_ACCESS_MODE" style="WIDTH: 152px"><option value=0> 只读</option><option value=1>读写</option></select></td>
	</tr>
	<tr>
	<input type="hidden" name="SNMP_COMM_COUNT" value="0"> 
	</tr>
	<tr>
	<input type="hidden" name="SNMP_ADD_COMM_WHICH_NUM" value="0"> 
	</tr>
	<tr>
		<td width=100% class=tb_content colspan=2>&nbsp</td>
	</tr>		
</table>
		
<table width=100% cellpadding=4 cellspacing=0>
	<tr  width=100% class="tb_head" colspan=2>
		<td width=25% align='center'><font size=2>团体名 </font></td>
		<td width=25% align='center'><font size=2>访问模式 </font></td>
		<td width=20% align="center"><font size=2>删除</font></td>		
	</tr>
	<script language="JavaScript">

	if(0 != snmp_comm_current_count)
	{	
		var comm_index = 0;
		for(comm_index=0; comm_index < MAX_COMM_COUNT; comm_index++)
		{	
			if(snmp_comm_name[comm_index])
			{	
				document.write('<tr  width=100% class=tb_content>');
				document.write('<td width=25% align="center">' + snmp_comm_name[comm_index] + '</td> ');
				document.write('<td width=25% align="center">' + snmp_comm_mode[comm_index] + '</td> ');
				document.write('<td width=20% align="center"><input type=button value="删除" onclick=apply_all(1,' +comm_index +') ></td></tr>');
			}
		}
	}
	</script>
</table>

<p>
<input type="hidden" name="SNMP_DEL_COMM_WHICHNUM" value="0">
<input type=button value="确认" onclick=apply_all(0,0) >
<input type=button value="取消" onclick=init() >
</p>
</form>

<script>pageTail();</script>
</body>
</html>
