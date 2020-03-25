#lang racket


(define (lookup given-key tree-of-records)
  (cond ((null? tree-of-records) #f)
        ((= given-key (key (entry tree-of-records)))
         (entry tree-of-records))
        (else
         (let ((left (lookup given-key (left-branch tree-of-records)))
               (right (lookup given-key (right-branch tree-of-records))))
           (if (number? left)
               left
               right)))))

(define (lookup1 given-key tree-of-records)
  (cond ((null? tree-of-records) #f)
        ((= given-key (key (entry tree-of-records)))
         (entry tree-of-records))
        ((< given-key (key (entry tree-of-records)))
         (lookup1 given-key (left-branch tree-of-records)))
        ((> given-key (key (entry tree-of-records)))
         (lookup1 given-key (right-branch tree-of-records)))))