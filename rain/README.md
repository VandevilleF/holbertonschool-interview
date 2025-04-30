Rain
====

*   Amateur
*   By: Jesse Hedden, Software Engineer at Holberton School
*   Weight: 1
*   Your score will be updated as you progress.

*   [Description](#description)

[Go to tasks](#)

Requirements
------------

### General

*   Allowed editors: `vi`, `vim`, `emacs`
*   All your files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
*   All your files should end with a new line
*   The first line of all your files should be exactly `#!/usr/bin/python3`
*   A `README.md` file, at the root of the folder of the project, is mandatory
*   Your code should use the `PEP 8` style (version 1.7.x)
*   You are not allowed to import any module
*   All modules and functions must be documented
*   All your files must be executable

Tasks
-----

### 0\. Rain

mandatory

Given a list of non-negative integers representing the heights of walls with unit width 1, as if viewing the cross-section of a relief map, calculate how many square units of water will be retained after it rains.

*   Prototype: `def rain(walls)`
*   `walls` is a list of non-negative integers.
*   Return: Integer indicating total amount of rainwater retained.
*   Assume that the ends of the list (before index 0 and after index walls\[-1\]) are **not** walls, meaning they will not retain water.
*   If the list is empty return `0`.

    jesse@ubuntu:~/$ cat 0_main.py
    #!/usr/bin/python3
    """
    0_main
    """
    rain = __import__('0-rain').rain

    if __name__ == "__main__":
        walls = [0, 1, 0, 2, 0, 3, 0, 4]
        print(rain(walls))
        walls = [2, 0, 0, 4, 0, 0, 1, 0]
        print(rain(walls))

    jesse@ubuntu:~/$
    jesse@ubuntu:~/$ ./0_main.py
    6
    6
    jesse@ubuntu:~/$


Visual representation of the walls `[0, 1, 0, 2, 0, 3, 0, 4]`

![](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2021/4/85ef782020ac6efdc7004b62ea86724a552285b4.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20250425%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20250425T121246Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=04d92fcde317d7ad782a79e2673fd2810134a85df2804c5949a08883aa8dfa9e)

Visual representation of the walls `[2, 0, 0, 4, 0, 0, 1, 0]`

![](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2021/4/9a27c3e4e214e55b3c0b8b1439fdc99b4a184ff5.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20250425%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20250425T121246Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=2e8309994af5cf60fa0141724a9410eb18f9f696282f6fef2eb010e49cf59610)

**Repo:**

*   GitHub repository: `holbertonschool-interview`
*   Directory: `rain`
*   File: `0-rain.py`
