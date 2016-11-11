<?php
/**
 * @file
 * api_site_configurations.default_password_policy.inc
 */

/**
 * Implements hook_default_password_policy().
 */
function api_site_configurations_default_password_policy() {
  $export = array();

  $password_policy = new stdClass();
  $password_policy->disabled = FALSE; /* Edit this to true to make a default password_policy disabled initially */
  $password_policy->api_version = 1;
  $password_policy->name = 'API Password length';
  $password_policy->config = 'a:14:{s:10:"alpha_case";a:1:{s:10:"alpha_case";i:0;}s:11:"alpha_count";a:1:{s:11:"alpha_count";s:1:"1";}s:9:"blacklist";a:1:{s:9:"blacklist";s:945:"1234567
12345678
123456789
password
password1
password12
password123
werty
baseball
dragon
football
monkey
letmein
abc123
111111
mustang
access
shadow
master
michael
admin123
adminabc
123123
asdasdd
696969
superman
batman
trustno1
1234567890
iloveyou
aaaaaa
654321
666666
sunshine
123321
letmein
monkey
asdfgh
shadow
princess
daniel
computer
121212
qwertyuiop
112233
asdfasdf
jessica
1q2w3e4r
welcome
1qaz2wsx
987654321
753951
chocolate
fuckyou
soccer
tigger
thomas
asdfghjkl
internet
michelle
123qwe
zxcvbnm
dreamweaver
7777777
maggie
qazwsx
jennifer
jordan
abcd1234
buster
555555
liverpool
whatever
11111111
102030
123123123
andrea
pepper
nicole
killer
abcdef
hannah
test
alexander
andrew
222222
joshua
freedom
samsung
asdfghj
purple
ginger
123654
matrix
secret
summer
1q2w3e
qweqwe1
qweqwe12
qweqwe123
qweqwe111
qweqwe222
qweqwe333
snoopy1";}s:10:"char_count";a:1:{s:10:"char_count";s:1:"6";}s:11:"consecutive";a:1:{s:22:"consecutive_char_count";s:0:"";}s:5:"delay";a:1:{s:5:"delay";s:0:"";}s:15:"drupal_strength";a:1:{s:15:"drupal_strength";s:0:"";}s:9:"int_count";a:1:{s:9:"int_count";s:1:"1";}s:14:"past_passwords";a:1:{s:14:"past_passwords";s:0:"";}s:12:"symbol_count";a:2:{s:12:"symbol_count";s:0:"";s:20:"symbol_count_symbols";s:30:"!@#$%^&*()_+=-|}{"?:><,./;\'\\[]";}s:8:"username";a:1:{s:8:"username";i:1;}s:7:"authmap";a:1:{s:11:"authmodules";a:0:{}}s:4:"role";a:1:{s:5:"roles";a:7:{i:1;i:0;i:2;i:0;i:3;i:0;i:7;i:0;i:5;i:0;i:6;i:0;i:4;i:0;}}s:6:"expire";a:5:{s:12:"expire_limit";s:1:"0";s:22:"expire_warning_message";s:46:"Your Password has expired please change it now";s:25:"expire_warning_email_sent";s:8:"-14 days";s:28:"expire_warning_email_message";s:0:"";s:28:"expire_warning_email_subject";s:92:"[user:name] you password on [site:name] shall expire in [password_expiration_date:interval] ";}}';
  $export['API Password length'] = $password_policy;

  return $export;
}
