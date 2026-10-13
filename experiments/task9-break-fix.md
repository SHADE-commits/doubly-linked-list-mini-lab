# Task 9 - Break and Fix

What I changed:
Di fungsi deleteNode, aku meng-comment-out bagian yang meng-update prev node sesudahnya (cur->next->prev = cur->prev dan update tail). Jadi hanya pointer next yang diperbaiki saat menghapus Song C.

What happened:
Forward traversal tetap benar: Song A, Song B, Song X, Song D, Song E.
Backward traversal salah. Hasilnya cuma Song E dan Song D, lalu berhenti dengan satu baris kosong. Song X, Song B, dan Song A tidak muncul.

Why:
Setelah Song C dihapus, B.next sudah menunjuk ke D, tapi D.prev masih menunjuk ke Song C yang sudah dihapus dari memori. Saat backward traversal sampai di D, program pindah lewat D.prev ke node yang sudah tidak valid, sehingga rantai ke belakang terputus. Pelajaran: saat delete di Doubly Linked List, kedua arah harus diupdate, yaitu next milik node sebelumnya dan prev milik node sesudahnya.