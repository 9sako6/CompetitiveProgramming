# coding: UTF-8
import re
import os
import requests
from bs4 import BeautifulSoup
from login import get_problems_list_html

def get_urls_dict(contest_name):
    """
    各問題の名前とurlの辞書を返す
    {'A':'https://abc111.contest.atcoder', 'B':...}
    """
    urls = []
    base_url = 'https://{}.contest.atcoder.jp'.format(contest_name)
    html_text = get_problems_list_html(contest_name)
    urls = re.findall('linkwrapper" href="([^"<>]+)">(\w)</a>', html_text)
    urls = dict(urls)
    urls = dict([(v, base_url + k) for k, v in urls.items()])
    print(urls)
    return urls

def download_samplecase(problem, url, contest_name):
    """
    問題ページからサンプルケースを抜き出し、テキストファイルとして出力する
    """
    html = requests.get(url)
    soup = BeautifulSoup(html.text, 'html.parser')

    for section in soup.findAll('section'):
        if re.match(r'入力例', section.find('h3').text):
            input_text = section.find('pre').text
            print('input')
            print(input_text)
            with open('{}_samplecase/{}_{}_input.txt'.format(
                contest_name, contest_name, problem
                ), 'w') as f:
                f.write(input_text)
        elif re.match(r'出力例', section.find('h3').text):
            output_text = section.find('pre').text
            print('output')
            print(output_text)
            with open('{}_samplecase/{}_{}_output.txt'.format(
                contest_name, contest_name, problem
                ), 'w') as f:
                f.write(output_text)
 
if __name__ == '__main__':
    contest_name = input('contest name: ')
    os.system('mkdir {}_samplecase'.format(contest_name))
    urls = get_urls_dict(contest_name)
    for problem, url in urls.items():
        download_samplecase(problem, url, contest_name)

