# coding: utf-8
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin
from getpass import getpass

def get_problems_list_html(contest_name):
    user = input('Username: ')
    passwd = getpass('Password: ')
    url = 'https://{}.contest.atcoder.jp/login'.format(contest_name)

    # login
    session = requests.session()
    login_info = { 'name':user, 'password':passwd }
    res = session.post(url, data=login_info)
    res.raise_for_status()

    # 問題一覧ページに移動
    problem_url = 'https://{}.contest.atcoder.jp/assignments'.format(contest_name)
    res = session.get(problem_url)
    res.raise_for_status()

    return(res.text)

